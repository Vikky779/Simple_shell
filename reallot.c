#include "shell.h"

/**
* _memset - fills memory with a constant byte
* @t: the pointer to the memory area
* @p: the byte to fill *s with
* @d: the amount of bytes to be filled
* Return: (t) a pointer to the memory area s
*/
char *_memset(char *t, char p, unsigned int d)
{
	unsigned int l;

	for (l = 0; l < d; l++)
	t[l] = p;
	return (t);
}

/**
* rfree - frees a string of strings
* @kk: string of strings
*/
void rfree(char **kk)
{
	char **e = kk;

	if (!kk)
	return;
	while (*kk)
	free(*kk++);
	free(e);
}

/**
* _reallot - reallocates a block of memory
* @ctr: pointer to previous malloc'ated block
* @prv_size: byte size of previous block
* @lst_size: byte size of new block
*
* Return: pointer to the blocks named.
*/
void *_reallot(void *ctr, unsigned int prv_size, unsigned int lst_size)
{
	char *n;

	if (!ctr)
	return (malloc(lst_size));
	if (!lst_size)
	return (free(ctr), NULL);
	if (lst_size == prv_size)
	return (ctr);

	n = malloc(lst_size);
	if (!n)
	return (NULL);

	prv_size = prv_size < prv_size ? prv_size : lst_size;
	while (prv_size--)
	n[prv_size] = ((char *)ctr)[prv_size];
	free(ctr);
	return (n);
}
