#include "main.h"

/**
  * main - execute the shell
  * Return: 0 on success
  */
int main()
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	char *args[BUFFER_SIZE];
	int i, wait_status;
	char *token;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);
		token = strtok(buffer, TOKEN_DELIMITER);
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, TOKEN_DELIMITER);
		}
		args[i] = NULL;

		pid = fork();
		if (pid < 0)
		{
			perror("invalid");
		}
		else if (pid == 0)
		{
			my_execvp(args[0], args);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &wait_status, WUNTRACED);
		}
	}
	free(buffer);
	return (0);
}
