#include "shell.h"

/**
* add_sec - adds a node to the start of the list
* @top: address of pointer to head node
* @str: str field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_sec(list_t **top, const char *str, int num)
{
	list_t *new_top;

	if (!top)
	return (NULL);
	new_top = malloc(sizeof(list_t));
	if (!new_top)
	return (NULL);
	_memset((void *)new_top, 0, sizeof(list_t));
	new_top->num = num;
	if (str)
	{
	new_top->str = _strdup(str);
	if (!new_top->str)
	{
	free(new_top);
	return (NULL);
	}
	}
	new_top->next = *top;
	*top = new_top;
	return (new_top);
}

/**
* add_sec_end - adds a node to the end of the list
* @top: address of pointer to head node
* @str: str field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_sec_end(list_t **top, const char *str, int num)
{
	list_t *new_sec, *sec;

	if (!top)
	return (NULL);

	sec = *top;
	new_sec = malloc(sizeof(list_t));
	if (!new_top)
	return (NULL);
	_memset((void *)new_sec, 0, sizeof(list_t));
	new_sec->num = num;
	if (str)
	{
	new_sec->str = _strdup(str);
	if (!new_sec->str)
	{
	free(new_sec);
	return (NULL);
	}
	}
	if (sec)
	{
	while (sec->next)
	sec = sec->next;
	sec->next = new_sec;
	}
	else
	*top = new_sec;
	return (new_sec);
}

/**
* print_list_str - prints only the str element of a list_t linked list
* @x: pointer to first node
*
* Return: size of list
*/
size_t print_list_str(const list_t *x)
{
	size_t f = 0;

	while (x)
	{
	_puts(x->str ? x->str : "(nil)");
	_puts("\n");
	x = x->next;
	f++;
	}
	return (f);
}

/**
* delete_sec_at_index - deletes node at given index
* @top: address of pointer to first node
* @index: index of node to delete
*
* Return: 1 on success, 0 on failure
*/
int delete_sec_at_index(list_t **top, unsigned int index)
{
	list_t *sec, *prev_sec;
	unsigned int f = 0;

	if (!top || !*top)
	return (0);

	if (!index)
	{
	node = *top;
	*top = (*top)->next;
	free(sec->str);
	free(sec);
	return (1);
	}
	sec = *top;
	while (sec)
	{
	if (f == index)
	{
	prev_sec->next = sec->next;
	free(sec->str);
	free(sec);
	return (1);
	}
	f++;
	prev_sec = sec;
	sec = sec->next;
	}
	return (0);
}

/**
* free_list - frees all nodes of a list
* @top_ptr: address of pointer to head node
*
* Return: void
*/
void free_list(list_t **top_ptr)
{
	list_t *sec, *next_sec, *top;

	if (!top_ptr || !*top_ptr)
	return;
	top = *top_ptr;
	sec = top;
	while (sec)
	{
	next_sec = sec->next;
	free(sec->str);
	free(sec);
	sec = next_sec;
	}
	*top_ptr = NULL;
}
