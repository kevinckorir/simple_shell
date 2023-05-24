#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void _execute(char *command, char **arguments);
void handle_exit();
int my_strlen(char *s);
char *parse_command(char *input);
int search_command(char *command);
void _execve(char *cmd, char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif /*SHELL_H*/
