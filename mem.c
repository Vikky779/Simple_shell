#include "shell.h"

/**
* mfree - frees a pointer and NULLs the address
* @btr: address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/
int mfree(void **btr)
{
	if (btr && *btr)
	{
	free(*btr);
	*btr = NULL;
	return (1);
	}
	return (0);
}
