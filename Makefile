CC = gcc
CFLAGS = -Wall

all: minishell

minishell: minishell.o utils.o
	$(CC) $(CFLAGS) -o minishell minishell.o utils.o

minishell.o: minishell.c utils.h
	$(CC) $(CFLAGS) -c minishell.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o minishell
