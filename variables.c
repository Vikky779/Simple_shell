#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
/**
* is_trail - Test if current char in buffer is a chain delimeter
* @inf: Parameter struct
* @buf: Char buffer
* @n: Address of current position in buf
* Return: Return 1 if it is  chain delimeter, 0 otherwise
*/
int is_trail(inf_t *inf, char *buf, size_t *n)
{
	size_t k = *n;

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
	buf[k] = 0;
	k++;
	inf->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
	buf[k] = 0;
	k++;
	inf->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';') /* found end of this command */
	{
	buf[k] = 0; /* replace semicolon with null */
	inf->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*n = k;
	return (1);
}

/**
* check_trail - checks to continue chaining based on last status
* @inf: Parameter struct
* @buf: Char buffer
* @j: Address of current position in buf
* @l: Starting position in buf
* @len: Length of buf
* Return: Void
*/
void check_trail(inf_t *inf, char *buf, size_t *j, size_t l, size_t len)
{
	size_t k = *j;

	if (inf->cmd_buf_type == CMD_AND)
	{
	if (inf->status)
	{
	buf[l] = 0;
	k = len;
	}
	}
	if (inf->cmd_buf_type == CMD_OR)
	{
	if (!inf->status)
	{
	buf[l] = 0;
	k = len;
	}
	}

	*j = k;
}

/**
* replace_alias - replaces an aliases in the tokenized string
* @inf: the parameter struct
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(inf_t *inf)
{
	int l;
	list_t *inst;
	char *d;

	for (l = 0; l < 10; l++)
	{
	inst = inst_starts_with(inf->alias, inf->argv[0], '=');
	if (!inst)
	return (0);
	free(inf->argv[0]);
	d = _strchr(inst->str, '=');
	if (!d)
	return (0);
	d = _strdup(d + 1);
	if (!d)
	return (0);
	inf->argv[0] = d;
	}
	return (1);
}

/**
* replace_var -This replaces vars in the tokenized string
* @inf: the parameter struct
* Return: 1 if replaced, 0 otherwise
*/
int replace_var(inf_t *inf)
{
	int l = 0;
	list_t *inst;

	for (l = 0; inf->argv[l]; l++)
	{
	if (inf->argv[l][0] != '$' || !inf->argv[l][1])
	continue;

	if (!_strcmp(inf->argv[l], "$?"))
	{
	replace_string(&(inf->argv[l]),
	_strdup(convert_number(inf->status, 10, 0)));
	continue;
	}
	if (!_strcmp(inf->argv[l], "$$"))
	{
	replace_string(&(inf->argv[l]),
	_strdup(convert_number(getpid(), 10, 0)));
	continue;
	}
	inst = inst_starts_with(inf->env, &inf->argv[l][1], '=');
	if (inst)
	{
	replace_string(&(inf->argv[l]),
	_strdup(_strchr(inst->str, '=') + 1));
	continue;
	}
	replace_string(&inf->argv[l], _strdup(""));

	}
	return (0);
}

/**
* replace_string - To replace string
* @prv: address of old string
* @lst: new string
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **prv, char *lst)
{
	free(*prv);
	*prv = lst;
	return (1);
}
