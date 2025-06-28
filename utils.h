#ifndef UTILS_H
#define UTILS_H

void trim_newline(char *str);
void parse_command(char *line, char **args);
int is_builtin(char *cmd);
void execute_builtin(char **args);
void execute_command(char *cmdline);

#endif
