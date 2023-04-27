#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

extern char **environ;

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_COMMAND_LENGTH/2];
    int status;

    while (1) {
	    int i = 0;
	    char *token;
        printf("$ ");
        fflush(stdout);

        fgets(command, MAX_COMMAND_LENGTH, stdin);
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = 0;

        token = strtok(command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
        } else if (strcmp(args[0], "help") == 0) {
            printf("Type commands and arguments, and hit enter.\n");
        } else {
            int found_command = 0;
            char* path = getenv("PATH");
            char* path_copy = strdup(path);
            char* dir = strtok(path_copy, ":");

            while (dir != NULL && !found_command) {
                char command_path[MAX_COMMAND_LENGTH];
		pid_t pid;

                snprintf(command_path, MAX_COMMAND_LENGTH, "%s/%s", dir, args[0]);

                if (access(command_path, X_OK) != -1) {
                    found_command = 1;

                    pid = fork();
                    if (pid == 0) {
                        execvp(command_path, args);
                        printf("Unknown command: %s\n", args[0]);
                        exit(0);
                    } else {
                        wait(&status);
                    }
                }

                dir = strtok(NULL, ":");
            }

            free(path_copy);

            if (!found_command) {
                printf("Unknown command: %s\n", args[0]);
            }
        }
    }

    return 0;
}
