#include "main.h"

/**
  * my_strtok - funciton breaks a string into a sequence of,
  * zero of more nonempty tokens.
  * @str: string to be parsed
  * @delim: specifies a set of bytes that delimit the tokens,
  * in the parsed string
  */
char *my_strtok(char *str, const char *delim)
{
	static char *p = 0;
	char *token = 0;

	if (p == NULL)
	{
		return (NULL);
	}
	if (str != NULL)
	{
		p = str;
	}
	token = p;
	while (*p != '\0' &&strchr(delim, *p) == NULL)
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
