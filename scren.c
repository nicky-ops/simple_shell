#include "main.h"

int main(void)
{
    while (1)
    {
        type_prompt();
        // read_command() and execute_command() functions here
    }
    return (0);
}

void type_prompt()
{
    static int first_prompt = 1;
    if (first_prompt) {
        const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
        write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
        first_prompt = 0;
    }       
    printf("#");
}

