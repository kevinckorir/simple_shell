#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
 *
 */

void _execve(char *cmd)
{
	pid_t pid;
	int i;
	char *args[] = {cmd, NULL};
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0);
	{
		execve(args[0], args, NULL);

		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
	{
		wait(NULL);
	}
	free(cmd);
}

