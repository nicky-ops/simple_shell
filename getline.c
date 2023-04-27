#include "main.h"
#include <stdlib.h>

void remove_comments(char *input);


/**
 * _readline - read input from stdin
 * Return: input string
 */
char *_readline()
{
	int p, buffer_size = BUFSIZE, rd;
	char q = 0;
	char *input = malloc(buffer_size);

	if (input == NULL)
	{
		free(input);
		return (NULL);
	}

	for (p = 0; q != EOF && p != '\n'; p++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &q, 1);
		if (rd == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		input[p] = q;
		if (input[0] == '\n')
		{
			free(input);
			return ("\0");
		}
		if (p >= buffer_size)
		{
			input = _realloc(input, buffer_size, buffer_size + 1);
			if (input == NULL)
			{
				return (NULL);
			}
			buffer_size++;
		}
	}
	input[p] = '\0';
	remove_comments(input);
	return (input);
}

/**
 * remove_comments - remove comments from input
 * @input: input string
 * Return: void
 */
void remove_comments(char *input)
{
	int p;

	for (p = 0; input[p] != '\0'; p++)
	{
		if (input[p] == '#')
		{
			input[p] = '\0';
			break;
		}
	}
}

