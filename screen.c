#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
  * print_prompt - display the prompt
  */
void print_prompt(void)
{
	static int first_time = 1;
	const char prompt[] = "$";

	if (first_time)
	{
		const char *CLEAR_SCREEN_ANSI = " \033[1;1H\033[2J";

		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	write(STDOUT_FILENO, prompt, 1);
}

/**
 * get_input - read user input and parse it into command and parameters
 * @command: string buffer to store command
 * @parameters: array buffer to store parameters
 */
void get_input(char command[], char *parameters[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *tokens[100], *token;

	for (;;)
	{
		int c = fgetc(stdin);

		line[count++] = (char) c;
		if (c == '\n')
		{
			break;
		}
	}
	if (count == 1)
	{
		return;
	}
	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \n");
	}
	strcpy(command, tokens[0]);
	for (j = 0; j < i; j++)
	{
		parameters[j] = tokens[j];
		parameters[i] = NULL;
	}
}

/**
 * main - execute the shell
 * Return: 0 on success
 */
int main(void)
{
	char command[100], *parameters[20];
	char current_directory[1024];

	while (1)
	{
		print_prompt();
		get_input(command, parameters);

		if (strcmp(command, "cd") == 0)
		{
			if (parameters[1] == NULL)
			{
				getcwd(current_directory, sizeof(current_directory));
				printf("%s\n", current_directory);
			}
			else
			{
				if (chdir(parameters[1]) != 0)
				{
					perror("chdir");
				}
			}
		}
		else
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				execvp(command, parameters);
				perror("exec");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}

