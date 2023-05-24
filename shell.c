#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void _execute(char *command, char **arguments);

int main()
{
    char *command = NULL;
    size_t command_length = 0;
    char *arguments[MAX_ARGUMENTS];
    char *token;
    int i = 0;

    while (1)
    {
        write(1, "& ", 2);

        if (_getline(&command, &command_length, stdin) == -1)
        {
            perror("Error: command not found");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (my_strlen(command) == 0)
        {
            continue;
        }

        token = strtok(command, " ");
        while (token != NULL && i < MAX_ARGUMENTS - 1)
        {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;
	if (strcmp(arguments[0], "exit") == 0)
	{
		exit_shel();
	}

        _execute(arguments[0], arguments);
    }

    free(command);

    return 0;
}
