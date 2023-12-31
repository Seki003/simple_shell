#include "shell.h"

/**
* is_cmd - Determines if a file is an executable command.
* @info: The info struct.
* @path: Path to the file.
*
* Return: 1 if true, 0 otherwise.
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info; /* Suppress unused parameter warning */
if (!path || stat(path, &st) != 0)
return (0);
if (S_ISREG(st.st_mode)) /* Check if the file is a regular file */
{
return (1);
}
return (0);
}

/**
* dup_chars - Duplicates characters from a string within a specified range.
* @pathstr: The PATH string.
* @start: Starting index (inclusive).
* @stop: Stopping index (exclusive).
*
* Return: Pointer to a new buffer containing the duplicated characters.
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024]; /* Static buffer for the duplicated characters */
int i = 0, k = 0;
for (k = 0, i = start; i < stop; i++)
{
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
}
buf[k] = '\0'; /* Null-terminate the buffer */
return (buf);
}

/**
* find_path - Finds the full path of a command in the PATH string.
* @info: The info struct.
* @pathstr: The PATH string.
* @cmd: The command to find.
*
* Return: The full path of the command if found, or NULL if not found.
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcpy(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i;
}
i++;
}
return (NULL);
}
