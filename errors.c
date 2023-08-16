#include "shell.h"

/**
* _errputs - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/
void _errputs(char *str)
{
	int t = 0;

	if (!str)
	return;
	while (str[t] != '\0')
	{
	_errputchar(str[t]);
	t++;
	}
}

/**
* _errputchar - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _errputchar(char c)
{
	static int l;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || l >= WRITE_BUF_SIZE)
	{
	write(2, buf, l);
	l = 0;
	}
	if (c != BUF_FLUSH)
	buf[l++] = c;
	return (1);
}

/**
* _putfd - writes the character c to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
	write(fd, buf, n);
	n = 0;
	}
	if (c != BUF_FLUSH)
	buf[n++] = c;
	return (1);
}

/**
* _putsfd - prints an input string
* @str: the string to be printed
* @fd: the filedescriptor to write to
*
* Return: the number of chars put
*/
int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
	return (0);
	while (*str)
	{
	p += _putfd(*str++, fd);
	}
	return (p);
}
