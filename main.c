#include "shell.h"

/**
* main - entry point
* @bf: arg count
* @pe: arg vector
*
* Return: 0 on success, 1 on error
*/
int main(int bf, char **pe)
{
	inf_t inf[] = { INF_INIT };
	int pd = 2;

	asm ("mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (pd)
	: "r" (pd));

	if (bf == 2)
	{
	fd = open(pe[1], O_RDONLY);
	if (fd == -1)
	{
	if (errno == EACCES)
	exit(126);
	if (errno == ENOENT)
	{
	_eputs(pe[0]);
	_eputs(": 0: Can't open ");
	_eputs(pe[1]);
	_eputchar('\n');
	_eputchar(BUF_FLUSH);
	exit(127);
	}
	return (EXIT_FAILURE);
	}
	inf->readpd = pd;
	}
	populate_env_list(inf);
	read_events(inf);
	hsh(inf, pe);
	return (EXIT_SUCCESS);
}
