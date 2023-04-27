#include "main.h"
#include <unistd.h>
#include <string.h>

int main() {
    char user_input[100];
    int input_len;
    while (1) {
        write(STDOUT_FILENO, "Enter a command: ", 17);
        input_len = read(STDIN_FILENO, user_input, 100);
        if (input_len == 5 && user_input[0] == 'e' && user_input[1] == 'x' && user_input[2] == 'i' && user_input[3] == 't' && user_input[4] == '\n') {
            write(STDOUT_FILENO, "Exiting program...\n", 19);
            break;
        } else {
            write(STDOUT_FILENO, "You entered: ", 13);
            write(STDOUT_FILENO, user_input, input_len);
        }
    }
    return 0;
}

