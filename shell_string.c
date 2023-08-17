#include "shell.h"
/**
 * _strlen - This returns the length of a string
 * @str: Length of string to be checked
 * Return: Length of string
 */
int _strlen(char *str)
{
	int p = 0;

	if (!str)
		return (0);

	while (*str++)
		p++;
	return (p);
}
/**
 * _strcmp - This compares two strings.
 * @d1: First string
 * @d2: Second string
 * Return: Negative if d1 < d2, positive if d1 > d2 and 0 if d1 == d2
 */
int _strcmp(char *d1, char *d2)
{
	while (*d1 && *d2)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
	}
	if (*d1 == *d2)
		return (0);
	else
		return (*d1 < *d2 ? -1 : 1);
}
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: The string to be searched
 * @needle: The substring to find
 * Return: The address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - This concatenates two strings
 * @t: Destination buffer
 * @s: Source buffer
 * Return: A pointer to destination buffer
 */
char *_strcat(char *t, char *s)
{
	char *new = t;

	while (*t)
		t++;
	while (*s)
		*t++ = *s++;
	*t = *s;
	return (new);
}
