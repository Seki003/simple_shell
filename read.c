#include "simple_shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * readln - the readln function is to read the command entered
 *
 * Return: always success
 */
char *readln(void)
{
char *ln = NULL;
size_t length = 0;
ssize_t x;

/* Printing the "$ " before taking the command and not printing it in EOF */
if (isatty(STDIN_FILENO))
	 write(STDOUT_FILENO, "$ ", 2);

	x = getline(&ln, &length, stdin);

if (x == -1)
{
	free(ln);
	return (NULL);
	}

	return (ln);
}
