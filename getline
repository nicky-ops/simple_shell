#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

char *_getline()
{
    static char buffer[BUFSIZE];
    static int pos = 0;
    static int size = 0;

    int rd = 0;
    char c = '\0';
    if (pos >= size || buffer[pos] == '\n') {
        rd = read(STDIN_FILENO, buffer, BUFSIZE);
        if (rd == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (rd == 0) {
            return NULL;
        }
        pos = 0;
        size = rd;
    }

    c = buffer[pos];
    pos++;

    return (c == '\n' || c == '\0') ? "" : &buffer[pos - 1];
}

