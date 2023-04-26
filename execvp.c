#include "main.h"
/**
  * my_execvp - executes a command from within a program
  * @file: name of file to be executed
  * @args: pointer to a pointer of arguments
  * Return: exit status
  */
int my_execvp(char *file, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
	if (execvp(file, args) == -1)
		{
			perror("execvp error");
			exit(EXIT_FAILURE);
		}
	}
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid error");
		exit(EXIT_FAILURE);
	}
	return (status);
}
