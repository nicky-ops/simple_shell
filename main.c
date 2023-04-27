#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define MAX_PATH_LEN 1024
#define MAX_LINE_LEN 2048

void execute(char *args[], char *envp[]) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        execve(args[0], args, envp);
        perror("execve failed");
        _exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork failed");
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_command(char *command, char *args[]) {
    char *token;
    int i = 0;

    token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int main(int argc, char *argv[], char *envp[]) {
    char *args[MAX_ARGS];
    char path[MAX_PATH_LEN];
    char line[MAX_LINE_LEN];
    int n;

    while (1) {
        /* Print prompt */
        if (isatty(STDIN_FILENO)) {
            printf("$ ");
            fflush(stdout);
        }

        /* Read input */
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        /* Remove newline character */
        n = strlen(line);
        if (n > 0 && line[n-1] == '\n') {
            line[n-1] = '\0';
        }

        /* Parse command */
        parse_command(line, args);

        /* Handle built-in commands */
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                /* No argument, change to home directory */
                chdir(getenv("HOME"));
            } else {
                /* Change to specified directory */
                if (chdir(args[1]) != 0) {
                    perror("cd failed");
                }
            }
        } else if (strcmp(args[0], "exit") == 0) {
            /* Exit the shell */
            exit(EXIT_SUCCESS);
        } else {
            /* Execute command */
            execute(args, envp);
        }
    }

    return 0;
}
