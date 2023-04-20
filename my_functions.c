#include "main.h"

void type_prompt()
{
    printf("> ");
    fflush(stdout);
}

void read_command(char cmd[], char *par[])
{
    char line[BUFFER_SIZE];
    int count = 0, i = 0, j = 0;

    if (my_fgets(line, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "read_command: error reading command\n");
        exit(EXIT_FAILURE);
    }

    while (line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            line[i] = '\0';
            if (j != 0) {
                par[count] = &line[j];
                count++;
            }
            j = i + 1;
        }
        i++;
    }
    par[count] = NULL;
    strcpy(cmd, line);
}
#include "main.h"

char *my_fgets(char *s, int size, FILE *stream)
{
    char *result = fgets(s, size, stream);
    if (result != NULL && strchr(s, '\n') == NULL)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    return result;
}

