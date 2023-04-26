#include "main.h"

/**
  * my_strtok - function breaks a string into a sequence of,
  * zero or more nonempty tokens.
  * @str: string to be parsed
  * @delim: specifies a set of bytes that delimit the tokens,
  * in the parsed string
  * Return: character of tokens
  */
char *my_strtok(char *str, const char *delim)
{
	static char *p = NULL;
	static char end = 0;
	char *token;
	int ln = 0;

	if (p == NULL)
	{
		return (NULL);
	}
	if (str != NULL)
	{
		p = str;
	}
	if (end)
	{
		return (NULL);
	}
	if (ln == 0)
	{
		end = 1;
		return (NULL);
	}
	token = p;
	p += ln;
	while (*p != '\0' && strchr(delim, *p) == NULL)
	{
		p++;
	}
	if (*p == '\0')
	{
		p = NULL;
		return (token);
	}
	*p = '\0';
	p++;
	return (token);
}
