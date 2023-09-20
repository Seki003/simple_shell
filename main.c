#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - our shell that reads and allocates a token and executes a certain command
 *
 * @ac: count of how many arguments we have
 * @argv: it is the arguments entered
 *
 * Return: 0 Success all the time
 */
int main(int ac, char **argv)
{
char *ln = NULL;
size_t len = 0;
ssize_t nread;
int stat = 0;
(void) ac;
(void) argv;

while (1)
{
nread = getline(&ln, &len, stdin);
if (nread == -1)
{
free(ln);
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (stat);
}

printf("Input Line: %s", ln);
}

free(ln);
return (0);
}
