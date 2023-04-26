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
		printf("$ ");
		my_fgets(buffer, BUFFER_SIZE, stdin);

		char *token = my_strtok(buffer, TOKEN_DELIMITER);
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = my_strtok(NULL, TOKEN_DELIMITER);
		}
		args[i] = NULL;
		pid_t pid;
		pid = my_fork();
		if (pid == 0)
		{
			my_execvp(args[0], args);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			my_waitpid(pid, &wait_status, WUNTRACED);
		}
	}
	free(buffer);
	return (0);
}
