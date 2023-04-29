#include "main.h"

/**
 * get_path - gets the value from env PATH
 * @env: env var pointer
 * Return: path
 */
char **get_path(char **env)
{
	char **pathways = NULL, *pathvalue = NULL;
	unsigned int inte = 0;

	pathvalue = strtok(env[inte], "=");
	while (env[inte])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = gen_tokens(pathvalue, ":");
			return (pathways);
		}
		inte++;
		pathvalue = strtok(env[inte], "=");
	}
	return (NULL);
}


/**
 * exec - function that executes a command
 * @cmd: command pointer
 * @n: shell name
 * @env: environmental variables pointer
 * @c: number of executed cycles
 * Return: nothing
 */
void exec(char **cmd, char *n, char **env, int c)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(cmd[0], "env") != 0)
		print_env(env);
	if (stat(cmd[0], &st) == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			perror(n);
			my_exit(cmd);
		}
	}
	else
	{
		pathways = get_path(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], cmd[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, cmd, env) < 0)
				{
					perror(n);
					free_memory(pathways);
					my_exit(cmd);
				}
				return;
			}
		}
		werror(n, c, cmd);
		free_memory(pathways);
	}
}


/**
 * werror - Prints message not found
 * @n: shell name
 * @c: number of cicles
 * @cmd: tokenized command
 * Return: nothing
 */
void werror(char *n, int c, char **cmd)
{
	char cee;

	cee = c + '0';
	write(STDOUT_FILENO, n, _strlen(n));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &cee, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}


/**
 * print_env - prints all enviromental variable.
 * @env: enviromental variables pointer
 * return: nothing
 */
void print_env(char **env)
{
	size_t size = 0, length = 0;

	while (env[size])
	{
		length = _strlen(env[size]);
		write(STDOUT_FILENO, env[size], length);
		write(STDOUT_FILENO, "\n", 1);
		size++;
	}
}
