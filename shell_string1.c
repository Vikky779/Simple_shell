#include "shell.h"

/**
* _strcpy - This function copies a string
* @t: destination string
* @s: source string
* Return: A pointer to destination
*/
char *_strcpy(char *t, char *s)
{
	int k = 0;

	if (t == s || s == 0)
	return (t);
	while (s[k])
	{
	t[k] = s[k];
	k++;
	}
	t[k] = 0;
	return (t);
}
/**
* _strdup - This duplicates a string
* @s: String to be duplicated
* Return: A pointer to the duplicated string
*/
char *_strdup(const char *s)
{
	int h = 0;
	char *dupl;

	if (s == NULL)
	return (NULL);
	while (*s++)
	h++;
	dupl = malloc(sizeof(char) * (h + 1));
	if (!dupl)
	return (NULL);
	for (h++; h--;)
	dupl[h] = *--s;
	return (dupl);
}
/**
*_puts - This prints an input string
*@s: String to be printed
* Return: Nothing
*/
void _puts(char *s)
{
	int k = 0;

	if (!s)
		return;
	while (s[k] != '\0')
	{
	_putchar(s[k]);
	k++;
	}
}

/**
* _putchar - This writes the character c to stdout
* @c: Character to be  printed
* Return: On success 1 and  error, -1 is returned
*/
int _putchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(1, buf, k);
	k = 0;
	}
	if (c != BUF_FLUSH)
	buf[k++] = c;
	return (1);
}
