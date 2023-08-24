#include "shell.h"
/**
 * _envi- prints the current environment
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _envi(info_t *inf)
{
	print_list_str(inf->envi);
	return (0);
}
/**
 * _getenvi - gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 * Return: the value
 */
char *_getenvi(info_t *inf, const char *name)
{
	list_t *node = inf->envi;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenvi - Initialize a new environment variable,
 * or modify an existing one
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */
int _setenvi(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenvi(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenvi - Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _unsetenvi(info_t *inf)
{
	int l;

	if (inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (l = 1; l <= inf->argc; l++)
		_unsetenvi(inf, inf->argv[l]);

	return (0);
}
/**
 * populate_envi_list - populates env linked list
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int populate_envi_list(info_t *inf)
{
	list_t *node = NULL;
	size_t l;

	for (l = 0; environ[l]; l++)
		add_node_end(&node, environ[l], 0);
	inf->envi = node;
	return (0);
}
