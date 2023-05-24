#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command)
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
        char *args[] = {command, NULL};
        execvp(command, args);

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

    while (1)
    {
        printf("$ ");

<<<<<<< HEAD
        if (fgets(command, sizeof(command), stdin) == NULL) {
            p
=======
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\nExit\n");
>>>>>>> 7e624e75a76ba5a9e42df8949e134016de682cc7
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0)
        {
            continue;
        }

        execute_command(command);
    }

    return 0;
}
