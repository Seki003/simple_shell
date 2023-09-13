#include "simple_shell.h"

/**
 * main - our shell that read and allocate a token and execute a certain comand
 *
 * @ac: count how many aurgument we have
 * @argv: it is the arguments entered
 *
 * Return: 0 Success all the time
*/
int main(int ac, char **argv)
{
	char *ln = NULL;
	/*char **cmd = NULL;*/
	int stat = 0;
	(void) acc;
	(void) argv;

	while (1)
	{
		ln = readln();
		if (ln == NULL) /*function needed for CTRL+D to reach EOF*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "/n", 1);
			return (stat);
		}

		/*cmd = tokenizer(ln);

		stat = _exe(command, argv);*/
	}

}
