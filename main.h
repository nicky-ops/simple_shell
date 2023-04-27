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
#define BUFSIZE 1024
typedef struct program_data program_data;

char *my_fgets(char *s, int size, FILE *stream);
char *my_strtok(char *str, const char *delim);
pid_t my_waitpid(pid_t pid, int *wstatus, int options);
pid_t my_fork(void);
int my_execvp(char *file, char **args);
void type_prompt(void);
void read_command(char cmd[], char *par[]);
int execute_command(program_data *prog_data);
char *_getline(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int history(char *input);
#endif
