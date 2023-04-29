#include "main.h"

/**
  * main - entry point to the program
  * @argc: number of arguments passed to the main function.
  * @argv: pointer to an array of type char containing,
  * arguments passed to the command line.
  * @env: pointer to enviroment variables.
  * Return: 0 on success
  */
int main(int argc, char **argv, char **env)
{
	int c;
	char *buffer = NULL, **cmd = NULL;
	size_t size = 0;
	ssize_t read_chars = 0;
	FILE *file;

	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		check(file);
	}
	while (1)
	{
		c++;
		my_prompt();
		read_chars = getline(&buffer, &size, stdin);
		if (read_chars == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			cmd = gen_tokens(buffer, " \0");
			free(buffer);
			if (_strcmp(cmd[0], "exit") != 0)
				my_exit(cmd);
			else if (_strcmp(cmd[0], "cd") != 0)
				cdir(cmd[1]);
			else
				child_process(cmd, argv[0], env, c);
		}
		fflush(stdin);
		buffer = NULL, size = 0;
	}
	r_chars(read_chars);
	return (EXIT_SUCCESS);
}
/**
  * r_chars -read characters
  * @chars: characters
  * Return: integer value
  */
int r_chars(ssize_t chars)
{
	if (chars == -1)
		return (EXIT_FAILURE);
	return (0);
}

/**
 * input_handle - function handles end of file erorr
 * @_prompt: prompt to handle.
 * Return: Nothing.
 */

void input_handle(int _prompt)
{
	(void)_prompt;
	write(STDOUT_FILENO, "\n(NMshell) $ ", 14);
}


/**
 * my_prompt - Prints the prompt to the stdandard output
 * Return: None
 */
void my_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(NMshell) $ ", 13);
}
/**
 * _EOF - Chaecks if buffer is EOF
 * @buffer: Pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
