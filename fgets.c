#include "main.h"

/**
  * fgets - funciton pointer that reads line of text from,
  * standard input.
  * @s: pointer to store input
  * @size: size of pointer
  * @stream: file stream
  * Return: s
  */

char *my_fgets(char *s, int size, FILE *stream)
{
	int i = 0, j;

	j = fgetc(stream);
	while (i < size - 1 && j != EOF && j != '\n')
	{
		s[i++] = (char) j;
	}
	if (j == '\n')
	{
		s[i++] = (char) j;
	}
	s[i] = '\0';
	if (i == 0 && j == EOF)
	{
		return (NULL);
	}
	return (s);
}
