#include "main.h"

/**
  * cdir -  function that changes working directory
  * @path: The new current working directory
  * Return: 0 on success, -1 on failure.
  */

int cdir(const char *path)
{
	char *buffer = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buffer, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}


/**
 * child_process - Function that creates a child process.
 * @cmd: Pointer to tokenized command
 * @n: Pointer to shell name.
 * @env: Enviromental variables pointer.
 * @c: No of executed cycles.
 * Return: Nothing.
 */
void child_process(char **cmd, char *n,  char **env, int c)
{
	int pid = 0;
	int status = 0;
	int waitError = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		my_exit(cmd);
	}
	else if (pid == 0)
	{
		exec(cmd, n, env, c);
		free_memory(cmd);
	}
	else
	{
		waitError = waitpid(pid, &status, 0);
		if (waitError < 0)
		{
			my_exit(cmd);
		}
		free_memory(cmd);
	}
}
