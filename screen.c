#include "main.h"
/**
  * print_prompt - display the prompt
  */
void print_prompt()
{
    static int first_time = 1;
    if (first_time) {
        const char* CLEAR_SCREEN_ANSI = " \033[1;1H\033[2J";
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_time = 0;
    }
    printf("#");
}
/**
 * get_input - read user input and parse it into command and parameters
 * @cmd: string buffer to store command
 * @parameters: array buffer to store parameters
 */

void get_input(char command[], char *parameters[])
{
    char line[1024];
    int count = 0, i = 0;
    char *tokens[100], *token;

    for (;;) {
        int c = fgetc(stdin);
        line[count++] = (char) c;
        if (c == '\n')
            break;
    }

    if (count == 1)
        return;

    token = strtok(line, "\n");

    while (token != NULL) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, "\n");
    }

    strcpy(command, tokens[0]);

    for (int j = 0; j < i; j++)
        parameters[j] = tokens[j];

    parameters[i] = NULL;
}

/**
 * main - execute the shell
 * Return: 0 on success
 */
int main()
{
    char cmd[100], command[100], *parameters[20];
    char *envp[] = {(char*)0};

    while (1) {
        print_prompt();
        get_input(command, parameters);
        if (fork() != 0)
            wait(NULL);
        else {
            strcpy(cmd, "/bin/");
            strcat(cmd, command);
            execve(cmd, parameters, envp);
        }
    }
    return 0;
}
