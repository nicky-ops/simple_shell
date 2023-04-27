#include "main.h"

/**
  * my_getline - reads a line from standard input
  * @lineptr: pointer to a pointer of characters
  * @n: number of lines
  * @stream: pointer to a file
  * Return: length
  */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL;
	size_t size = 0;
	size_t len = 0;
	int c;

	while ((c = fgetc(stream)) != EOF)
	{
		if (size <= len + 1)
		{
			size += 256;
			line = realloc(line, size);
			if (!line)
			{
				return (-1);
			}
		}
		line[len++] = c;
		if (c == '\n')
		{
			break;
		}
	}
	if (len == 0)
	{
		return (-1);
	}
	line[len] = '\0';
	if (*lineptr)
	{
		free(*lineptr);
	}
	*lineptr = line;
	*n = size;
	return (len);
}
