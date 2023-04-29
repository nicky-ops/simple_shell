#ifndef MAIN_H_
#define MAIN_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int r_chars(ssize_t chars);
void check(FILE *file);
void my_prompt(void);
void imput_handle(int tokens);
void _EOF(char *buffer);
void child_process(char **cmd, char *n, char **env, int c);
int cdir(const char *path);
void exec(char **cmd, char *n, char **env, int c);
void print_env(char **env);
char **get_path(char **env);
void werror(char *n, int c, char **cmd);
char **gen_tokens(char *buffer, const char *size);
void free_memory(char **cmd);
void my_exit(char **cmd);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

#endif
