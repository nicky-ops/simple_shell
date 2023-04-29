#include "main.h"

/**
 * my_exit - free all the memory allocated and exit
 * @cmd: pointer to command memory
 * Return: Nothing.
 */

void my_exit(char **cmd)
{
	size_t size = 0;

	if (cmd == NULL)
		return;

	while (cmd[size])
	{
		free(cmd[size]);
		size++;
	}

	if (cmd[size] == NULL)
		free(cmd[size]);
	free(cmd);
	exit(EXIT_FAILURE);
}


/**
 * free_memory - frees all the memory allocated for command
 * @cmd: Pointer to allocated memory
 * Return: nothing.
 */
void free_memory(char **cmd)
{
	size_t size = 0;

	if (cmd == NULL)
		return;

	while (cmd[size])
	{
		free(cmd[size]);
		size++;
	}

	if (cmd[size] == NULL)
		free(cmd[size]);
	free(cmd);
}
