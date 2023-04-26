#include "main.h"
/**
 * execute_command - execute the  command
 * @prog_data: specified pointer
 * Return: 0 on success, -1 on failure.
 */
int execute_command(program_data *prog_data)
{
	int result = 0, status;
	pid_t pidd;

	result = search_builtins(prog_data);
	if (result >= 0)
		return (result);

	result = find_program(prog_data);
	if (result)
	{
		return (result);
	}
	else
	{
		pidd = fork();
		if (pid < 0)
		{
			perror(prog_data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			result = execve(prog_data->tokens[0], prog_data->tokens, prog_ data->env);


			if (result == -1)
				perror(prog_data->command_name), exit(EXIT_FAILURE);
		}
		else
			waitpid(child_pid, &child_status, 0);

			if (WIFEXITED(child_(status))
				exit_status = WEXITSTATUS(child_status);
			else if (WIFSIGNALED(child_status))
				exit_status = 128 + WTERMSIG(child_status);
		}
	}
	return (0);
}

