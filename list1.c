#include "shell.h"

/**
* list_len - determines length of linked list
* @p: pointer to first node
*
* Return: size of list
*/
size_t list_len(const list_t *p)
{
	size_t e = 0;

	while (p)
	{
	p = p->next;
	e++;
	}
	return (e);
}

/**
* list_to_strings - returns an array of strings of the list->str
* @top: pointer to first node
*
* Return: array of strings
*/
char **list_to_strings(list_t *top)
{
	list_t *sec = top;
	size_t l = list_len(top), n;
	char **strs;
	char *str;

	if (!top || !l)
	return (NULL);
	strs = malloc(sizeof(char *) * (l + 1));
	if (!strs)
	return (NULL);
	for (l = 0; sec; sec = sec->next, l++)
	{
	str = malloc(_strlen(sec->str) + 1);
	if (!str)
	{
	for (n = 0; n < l; n++)
	free(strs[n]);
	free(strs);
	return (NULL);
	}

	str = _strcpy(str, node->str);
	strs[l] = str;
	}
	strs[l] = NULL;
	return (strs);
}


/**
* print_list - prints all elements of a list_t linked list
* @p: pointer to first node
*
* Return: size of list
*/
size_t print_list(const list_t *p)
{
	size_t e = 0;

	while (p)
	{
	_puts(convert_number(p->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(p->str ? p->str : "(nil)");
	_puts("\n");
	p = p->next;
	e++;
	}
	return (e);
}

/**
* sec_starts_with - returns node whose string starts with prefix
* @sec: pointer to list head
* @prefix: string to match
* @d: the next character after prefix to match
*
* Return: match node or null
*/
list_t *sec_starts_with(list_t *sec, char *prefix, char d)
{
	char *f = NULL;

	while (sec)
	{
	f = starts_with(sec->str, prefix);
	if (f && ((d == -1) || (*f == d)))
	return (sec);
	sec = sec->next;
	}
	return (NULL);
}

/**
* get_sec_index - gets the index of a node
* @top: pointer to list head
* @sec: pointer to the node
*
* Return: index of node or -1
*/
ssize_t get_sec_index(list_t *top, list_t *sec)
{
	size_t l = 0;

	while (top)
	{
	if (top == sec)
	return (l);
	top = top->next;
	l++;
	}
	return (-1);
}
