#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

int main(int argc, char **argv)
{
    char *input = NULL;
    size_t buf = 0;
    size_t z;
    int i = 0;
    char *token;
    char *delim = " ";

    while (1) 
    {
	    write(1, "$ ", 2);
	    fflush(stdout);
	    
	    z = getline(&input, &buf, stdin);
	    if (z == -1)
	    {
		    perror("Error");
		    break;
	    }
	    input[strcspn(input, "\n")] = "\0";
	    if (my_strlen(input) == 0)
	    {
		    continue;
	    }
	    token = strtok(input, delim);
	    for (; token != NULL;)
	    {
		    argv[i++] = token;
		    token = strtok(NULL, delim);
	    }
	    _execve(argv[0], argv);
    }
    return (0);
}
