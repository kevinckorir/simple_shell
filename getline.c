#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t position = 0;
    int c;
    size_t buffer_size = BUFFER_SIZE;
    char *buffer = malloc(buffer_size);
    char *new_buffer;

    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1;
    }

    if (buffer == NULL)
    {
        return -1;
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (position >= buffer_size - 1)
        {
            buffer_size *= 2;
            new_buffer = realloc(buffer, buffer_size);
            if (new_buffer == NULL)
            {
                free(buffer);
                return -1;
            }
            buffer = new_buffer;
        }

        buffer[position++] = (char)c;

        if (c == '\n')
        {
            break;
        }
    }

    buffer[position] = '\0';

    if (position == 0 && c == EOF)
    {
        free(buffer);
        return -1;
    }

    *lineptr = buffer;
    *n = buffer_size;

    return position;
}
