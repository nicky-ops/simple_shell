#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    pid_t pid;
    int status;

    while(1) {
	    int i = 0;
        printf("Shell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        token = strtok(command, " \n");
        while(token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL;
        if(strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        pid = fork();
        if(pid == 0) {
            execvp(args[0], args);
            printf("Command not found.\n");
            exit(1);
        }
        else if(pid < 0) {
            printf("Error: Fork failed.\n");
        }
        else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

