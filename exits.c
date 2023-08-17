#include "shell.h"
/**
 **_strncpy - This function copies a string
 *@dest: The destination string to be copied to
 *@src: The source string
 *@m: Characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int i, k;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < m - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < m)
	{
		k = i;
		while (k < m)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}
/**
 **_strncat - This concatenates two strings
 *@dest: First string
 *@src: Second string
 *@m: Amount of bytes to be maximally used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int i, p;
	char *s = dest;

	i = 0;
	p = 0;

	while (dest[i] != '\0')
		i++;
	while (src[p] != '\0' && p < m)
	{
		dest[i] = src[p];
		i++;
		p++;
	}
	if (p < n)
		dest[i] = '\0';
	return (s);
}
/**
 **_strchr - This locates a character in a string
 *@f: String to be parsed
 *@p: Character to look for
 *Return: (f) a pointer to the memory area
 */
char *_strchr(char *f, char p)
{
	do {
		if (*f == p)
			return (f);
	} while (*f++ != '\0');

	return (NULL);
}
