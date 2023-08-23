#include "shell.h"

/**
* clr_inf - initializes inf_t struct
* @inf: struct address
*/
void clr_inf(inf_t *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
* set_inf - initializes inf_t struct
* @inf: struct address
* @bf: argument vector
*/
void set_inf(inf_t *inf, char **bf)
{
	int e = 0;

	inf->fname = bf[0];
	if (inf->arg)
	{
	inf->argv = strtow(inf->arg, " \t");
	if (!inf->argv)
	{
	inf->argv = malloc(sizeof(char *) * 2);
	if (inf->argv)
	{
	inf->argv[0] = _strdup(inf->arg);
	inf->argv[1] = NULL;
	}
	}
	for (e = 0; inf->argv && inf->argv[e]; e++)
		;
	inf->argc = e;

	replace_alias(inf);
	replace_vars(inf);
	}
}

/**
* free_inf - frees inf_t struct fields
* @inf: struct address
* @tod: true if freeing all fields
*/
void free_inf(inf_t *inf, int tod)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (tod)
	{
	if (!inf->cmd_buf)
	free(inf->arg);
	if (inf->env)
	free_list(&(inf->env));
	if (inf->history)
	free_list(&(info->history));
	if (inf->alias)
	free_list(&(inf->alias));
	ffree(inf->environ);
	inf->environ = NULL;
	bfree((void **)inf->cmd_buf);
	if (inf->readfd > 2)
	close(inf->readfd);
	_putchar(BUF_FLUSH);
	}
}

