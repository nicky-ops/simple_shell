#include "main.h"

/**
  * my_fork - creates a child process
  * Return: process id
  */

pid_t my_fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
	return (pid);
}

