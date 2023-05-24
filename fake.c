#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char **argv)
{
    char *n = NULL;
    size_t buf = 0;
    size_t z;
    int i = 0;
    char *token;
    char *delim = " ";
    char *cmd = getenv("PATH");
    pid_t p;

    while (1) {
        write(1, "$ ", 2);
        fflush(stdout);

        z = getline(&n, &buf, stdin);
        if (z == -1) 
            break;
 	token = strtok(n, delim);
	for (; token != NULL;)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
		p = fork();
		if (p == 0)
		{
			execve(argv[0], argv, environ);
		}
		else if (p < 0)
			perror("Error");
		else 
			wait(NULL);
	}
	free(n);
    }
    return (0);
    
}
