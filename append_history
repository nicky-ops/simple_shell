#include "main.h"
#include <fcntl.h>
#include <unistd.h>


/**
 * history - Write user input to a history file.
 * @user_input: User input to write to history.
 * Return: -1 on failure, 0 on success.
 */
int history(char *user_input)
{
    char *filename = ".simple_shell_history";
    ssize_t file_descriptor, write_count;
    int input_len = 0;

    if (!filename)
        return (-1);

    file_descriptor = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
    if (file_descriptor < 0)
        return (-1);

    if (user_input)
    {
        while (user_input[input_len])
            input_len++;
        write_count = write(file_descriptor, user_input, input_len);
        if (write_count < 0)
            return (-1);
    }
    close(file_descriptor);
    return (0);
}

/**
 * free_env - Free array of environment variables.
 * @env: Array of environment variables.
 * Return: void.
 */
void free_env(char **env)
{
    int j;

    for (j = 0; env[j]; j++)
    {
        free(env[j]);
    }
}

