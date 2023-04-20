#include "main.h"

/**
 * main - Displays prompt and waits for user input
 * Return: Always 0
 */
int main(void)
{
    char buffer[100], command[100], *args[20];
    char *envp[] = {NULL};
    while (1)
    {
        type_prompt();
        read_command(command, args);
        if (fork() != 0)
        {
            wait(NULL);
        }
        else
        {
            if (command[0] != '\0')
            {
                strcpy(buffer, "/bin/");
                strcat(buffer, command);
                execve(buffer, args, envp);
            }
            else
            {
                printf("Invalid command\n");
            }
        }
    }
    return (0);
}

