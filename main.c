#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_COMMAND_LENGTH/2];
    int should_run = 1;

    while (should_run) {
	    int i = 0;
	    char *token;

        printf(">");
        fflush(stdout);

        fgets(command, MAX_COMMAND_LENGTH, stdin);
        token = strtok(command, " \n");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
        } else if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
        } else if (strcmp(args[0], "help") == 0) {
            printf("Type commands and arguments, and hit enter.\n");
        } else {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                printf("Unknown command: %s\n", args[0]);
                exit(0);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}
