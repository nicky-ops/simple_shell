#include "main.h"
/**
  * my_waitpid - wait for child to change state
  * @pid: process id
  * @wstatus: pointer to status variable
  * @options: parameters
  * Return: exit status
  */


pid_t my_waitpid(pid_t pid, int *wstatus, int options)
{
	struct user_regs_struct regs;
	long int value1, value2, value3, value4;

	value1 = ptrace(PTRACE_ATTACH, pid, NULL, NULL);
	value2 = waitpid(pid, wstatus, options);
	value3 = ptrace(PTRACE_GETREGS, pid, NULL, &regs);
	value4 = ptrace(PTRACE_DETACH, pid, NULL, NULL);
	if (value1 == -1)
	{
		perror("ptrace attach error");
		exit(EXIT_FAILURE);
	}
	if (value2 == -1)
	{
		perror("waitpid error");
		exit(EXIT_FAILURE);
	}
	if (value3 == -1)
	{
		perror("ptrace getregs error");
		exit(EXIT_FAILURE);
	}
	if (value4 == -1)
	{
		perror("ptrace detach error");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(*wstatus))
	{
		return (WEXITSTATUS(*wstatus));
	}
	else
	{
		return (regs.orig_rax);
	}
}
