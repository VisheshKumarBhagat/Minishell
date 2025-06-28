#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "utils.h"

#define MAX_CMD 1024
#define MAX_ARGS 64

void execute_pipeline(char *cmdline);
void execute_redirects(char **args);

int main() {
    char line[MAX_CMD];

    while (1) {
        printf("minishell> ");
        if (!fgets(line, MAX_CMD, stdin))
            break;

        trim_newline(line);
        if (strchr(line, '|')) {
            execute_pipeline(line);
        } else {
            execute_command(line);
        }
    }

    return 0;
}

void execute_command(char *cmdline) {
    char *args[MAX_ARGS];
    parse_command(cmdline, args);

    if (args[0] == NULL)
        return;

    if (is_builtin(args[0])) {
        execute_builtin(args);
        return;
    }

    pid_t pid = fork();
    if (pid == 0) {
        execute_redirects(args);
        execvp(args[0], args);
        perror("exec");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork");
    }
}

void execute_redirects(char **args) {
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], "<") == 0) {
            int fd = open(args[i + 1], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[i] = NULL;
        } else if (strcmp(args[i], ">") == 0) {
            int fd = open(args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[i] = NULL;
        }
    }
}

void execute_pipeline(char *cmdline) {
    char *cmd1 = strtok(cmdline, "|");
    char *cmd2 = strtok(NULL, "|");

    if (!cmd2) {
        execute_command(cmd1);
        return;
    }

    int pipefd[2];
    pipe(pipefd);

    pid_t p1 = fork();
    if (p1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execute_command(cmd1);
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execute_command(cmd2);
        exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);
}
