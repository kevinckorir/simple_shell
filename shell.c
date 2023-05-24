#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command, char **arguments)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Error: Forking process failed");
        return;
    }
    else if (pid == 0)
    {
        execvp(command, arguments);

        perror("Error: Command not found");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    char *token;
    int i = 0;

    while (1)
    {
        printf("$ ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\nExit\n");
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

        execute_command(arguments[0], arguments);
    }

    return 0;
}
