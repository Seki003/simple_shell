#include "shell.h"

/**
 * interactive - checks if the shell is in interactive mode
 * @info: pointer to info_t structure
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, const char *delim)
{
	while (*delim)
	{
	if (*delim == c)
	{
		return (1);
	}
	delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int _atoi(const char *s)
{
	int i = 0, sign = 1, flag = 0, output = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')

	{
		flag = 1;
		output = output * 10 + (s[i] - '0');
		i++;
	}

	return (flag == 0 ? 0 : output * sign);
}
