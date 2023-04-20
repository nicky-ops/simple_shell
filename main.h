#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/user.h>

#define TOKEN_DELIMITER " \t\r\n\a"
#define BUFFER_SIZE 1024

char *my_fgets(char *s, int size, FILE *stream);
char *my_strtok(char *str, const char *delim);
pid_t my_waitpid(pid_t pid, int *wstatus, int options);
pid_t my_fork(void);
int my_execvp(char *file, char **args);
void type_prompt();
void read_command ( char cmd[], char *par[] );


#endif
