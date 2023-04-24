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
	int j;
	s = (char *)malloc(size * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	int j = fgetc(stream);

	while ((j != EOF) && (j != '\n') && (i < size - 1))
	{
		s[i++] = (char) j;
		j = fgetc(stream);
	}
	s[i] = '\0';
	if (i == 0 && j == EOF)
	{
		return (NULL);
	}
	return (s);
}
