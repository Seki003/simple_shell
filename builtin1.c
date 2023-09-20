#include "shell.h"

/**
 * _myhistory - displays the command history with line numbers.
 * @info: Structure containing potential arguments.
 *
 * Return: always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - removes an alias.
 * @info: Parameter struct.
 * @str: The alias string to unset.
 *
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *equals_pos, saved_char;
int ret;
list_t *node;

equals_pos = _strchr(str, '=');
if (!equals_pos)
return (1);

saved_char = *equals_pos;
*equals_pos = '\0';


node = node_starts_with(info->alias, str, '=');

if (node)
{
ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, node));
}
else
{

ret = 1;
}

*equals_pos = saved_char;
return (ret);
}

/**
 * set_alias - sets an alias.
 * @info: Parameter struct.
 * @str: The alias string to set.
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *equals_pos;

equals_pos = _strchr(str, '=');
if (!equals_pos)
return (1);

if (!*++equals_pos)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *equals_pos, *alias_start;

if (node)
{
equals_pos = _strchr(node->str, '=');
alias_start = node->str;

while (alias_start <= equals_pos)
{
_putchar(*alias_start++);
}
_putchar('\\');
_puts(equals_pos + 1);
_puts("'\n");
return (0);
}

return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 *
 * Return: always 0
 */
int _myalias(info_t *info)
{
int i;
char *equals_pos;
list_t *node;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}

for (i = 1; info->argv[i]; i++)
{
equals_pos = _strchr(info->argv[i], '=');
if (equals_pos)
print_alias(info->alias);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
