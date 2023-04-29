#include "main.h"
/**
 * check - checks a file
 * @file: file name
 * Return: void
 */
void check(FILE *file)
{
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
}
