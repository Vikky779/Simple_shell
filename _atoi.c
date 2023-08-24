#include "shell.h"
/**
* interactive - returns true if interactive mode
* @inf: struct address
* Return: 1 if interactive mode, 0 otherwise
*/
int interactive(inf_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
* is_delim - checks if character is a delimeter
* @c: the char to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
*/
int is_delim(char c, char *delim)
{
	while (*delim)
	if (*delim++ == c)
	return (1);
	return (0);
}

/**
* _isalpha - checks for alphabetic character
* @t: The character to input
* Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int t)
{
	if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
	return (1);
	else
	return (0);
}
/**
* _atoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/
int _atoi(char *s)
{
	int l, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (l = 0; s[l] != '\0' && flag != 2; l++)
{
	if (s[l] == '-')
	sign *= -1;

	if (s[l] >= '0' && s[l] <= '9')
{
	flag = 1;
	result *= 10;
	result += (s[l] - '0');
}
	else if (flag == 1)
	flag = 2;
}

	if (sign == -1)
	output = -result;
	else
	output = result;

	return (output);
}
