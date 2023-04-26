#include "main.h"
/**
  * type_prompt - function promps user in the standard,
  * output
 */

void type_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * read_command - reads commands and its arguments from,
 * the standard input.
 * @cmd: array of characters
 * @par: pointer to array of character arguments
 */
void read_command(char cmd[], char *par[])
{
	char line[BUFFER_SIZE];
	int count = 0, i = 0, j = 0;

	if (my_fgets(line, BUFFER_SIZE, stdin) == NULL)
	{
		fprintf(stderr, "read_command: error reading command\n");
		exit(EXIT_FAILURE);
	}
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		{
			line[i] = '\0';
			if (j != 0)
			{
				par[count] = &line[j];
				count++;
			}
			j = i + 1;
		}
		i++;
	}
	par[count] = NULL;
	strcpy(cmd, line);
}

/**
  * my_fgets - function pointer that reads line of text from,
  * standard input.
  * @s: pointer to store input
  * @size: size of pointer
  * @stream: file stream
  * Return: char result
 */

char *my_fgets(char *s, int size, FILE *stream)
{
	char *result = fgets(s, size, stream);

	if (result != NULL && strchr(s, '\n') == NULL)
	{
		int ch;

		while ((ch = getchar()) != '\n' && ch != EOF)
		{
			return (NULL);
	}
	return (result);
}
