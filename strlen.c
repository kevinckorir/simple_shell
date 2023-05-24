#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * strlen - function that print length of string
 * @s: string
 * Return: lenght of string
 */

int my_strlen(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
		;
	return (i);
}
