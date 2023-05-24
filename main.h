#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(char* command);
void handle_exit();
int my_strlen(char *s);
char* parse_command(char* input);
int search_command(char* command);

#endif /*MAIN_H*/
