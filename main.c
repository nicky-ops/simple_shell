#include "main.h"

/**
  * main - execute the shell
  * Return: 0 on success
  */
int main(void)
{
	char *buffer = malloc(BUFFER_SIZE * (sizeof(char)));
	char *args[BUFFER_SIZE];
	int wait_status;

	while (1)
	{

		pid_t pid;
		char *token;
		int i = 0;

		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);
		token = strtok(buffer,TOKEN_DELIMITER);
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, TOKEN_DELIMITER);
		}
		args[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			waitpid(pid, &wait_status, WUNTRACED);
		}
	}
	free(buffer);
	return (0);
}