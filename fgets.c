#include "main.h"

/**
  * my_fgets - function pointer that reads line of text from,
  * standard input.
  * @s: pointer to store input
  * @size: size of pointer
  * @stream: file stream
  * Return: s
  */

char *my_fgets(char *s, int size, FILE *stream)
{
	int i = 0;
	int j = fgetc(stream);

	if (s == NULL || stream == NULL)
	{
		return (NULL);
	}

	while ((j != EOF) && (j != '\n') && (i < size - 1))
	{
		s[i++] =j;
		if (j == '\n')
		{
			break;
		}
	}
	s[i] = '\0';
	if (i == 0 && j == EOF)
	{
		return (NULL);
	}
	return (s);
}
