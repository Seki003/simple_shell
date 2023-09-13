#include "simple_shell.h"

/**
 * readln - the readln function is to read the command enterd
 *
 * Return: always success
*/
char *readln(void)
{
	char *ln = NULL;
	size_t lenth = 0;
	size_t x;

	/*printing the "$ " before taking the command and not printing it in EOF*/
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	x = getline(&ln, &lenth, stdin);
	if (x == -1)
	{
		free(ln);
		return (NULL);
	}

	return (ln);
}
