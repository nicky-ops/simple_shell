#include "main.h"
/**
  * main - execute the shell
  * Return: 0 on success
  */
int main(void)
{
	char *buffer = malloc(BUFFER_SIZE * (sizeof(char))), *args[BUFFER_SIZE];
	int wait_status, i = 0;

	while (1)
	{
		pid_t pid;
		char *token;

		printf("$ ");
		fgets(buffer, BUFFER_SIZE, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		if (strcmp(buffer, "exit") == 0)
		{
			exit(0);
		}
		token = strtok(buffer, TOKEN_DELIMITER);
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
