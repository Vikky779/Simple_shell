#include "shell.h"

/**
* _eratoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*       -1 on error
*/
int _eratoi(char *s)
{
	int l = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* POR: why does this make main return 255? */
	for (l = 0;  s[l] != '\0'; i++)
	{
	if (s[l] >= '0' && s[l] <= '9')
	{
	result *= 10;
	result += (s[l] - '0');
	if (result > INT_MAX)
	return (-1);
	}
	else
	return (-1);
	}
	return (result);
}

/**
* print_err - prints an error message
* @inf: the parameter & return info struct
* @str: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
*        -1 on error
*/
void print_err(info_t *inf, char *str)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(str);
}

/**
* print_f - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_f(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int p, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
	__putchar = _eputchar;
	if (input < 0)
	{
	_abs_ = -input;
	__putchar('-');
	count++;
	}
	else
	_abs_ = input;
	current = _abs_;
	for (p = 1000000000; p > 1; p /= 10)
	{
	if (_abs_ / p)
	{
	__putchar('0' + current / p);
	count++;
	}
	current %= p;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
* convert_number - converter function, a clone of itoa
* @numb: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int numb, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ttr;
	unsigned long n = numb;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
	n = -numb;
	sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ttr = &buffer[49];
	*ttr = '\0';

	do	{
	*--ttr = array[n % base];
	n /= base;
	} while (n != 0);

	if (sign)
	*--ttr = sign;
	return (ttr);
}

/**
* remove_comments - function replaces first instance of '#' with '\0'
* @buf: address of the string to modify
*
* Return: Always 0;
*/
void remove_comments(char *buf)
{
	int o;

	for (o = 0; buf[i] != '\0'; i++)
	if (buf[o] == '#' && (!o || buf[o - 1] == ' '))
	{
	buf[o] = '\0';
	break;
	}
}
