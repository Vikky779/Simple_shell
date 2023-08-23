#include "shell.h"

/**
* **strfow - splits a string into words. Repeat delimiters are ignored
* @ctr: the input string
* @p: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strfow(char *ctr, char *p)
{
	int g, h, i, j, numwords = 0;
	char **d;

	if (ctr == NULL || ctr[0] == 0)
	return (NULL);
	if (!p)
	p = " ";
	for (g = 0; ctr[g] != '\0'; g++)
	if (!is_delim(ctr[g], p) && (is_delim(ctr[g + 1], p) || !ctr[g + 1]))
	numwords++;

	if (numwords == 0)
	return (NULL);
	d = malloc((1 + numwords) * sizeof(char *));
	if (!d)
	return (NULL);
	for (g = 0, h = 0; h < numwords; h++)
	{
	while (is_delim(ctr[g], p))
	g++;
	i = 0;
	while (!is_delim(ctr[g + i], p) && ctr[g + i])
	i++;
	d[h] = malloc((i + 1) * sizeof(char));
	if (!d[h])
	{
	for (i = 0; i < h; i++)
	free(d[i]);
	free(d);
	return (NULL);
	}
	for (j = 0; j < i; j++)
	s[h][j] = ctr[g++];
	s[h][j] = 0;
	}
	d[h] = NULL;
	return (d);
}

/**
* **strfow2 - splits a string into words
* @ctr: the input string
* @p: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strfow2(char *ctr, char p)
{
	int g, h, i, j, numwords = 0;
	char **d;

	if (ctr == NULL || ctr[0] == 0)
	return (NULL);
	for (g = 0; ctr[g] != '\0'; g++)
	if ((ctr[g] != p && ctr[g + 1] == p) ||
	(ctr[g] != p && !ctr[g + 1]) || ctr[g + 1] == p)
	numwords++;
	if (numwords == 0)
	return (NULL);
	d = malloc((1 + numwords) * sizeof(char *));
	if (!d)
	return (NULL);
	for (g = 0, h = 0; h < numwords; h++)
	{
	while (ctr[g] == p && ctr[g] != p)
	g++;
	i = 0;
	while (ctr[g + i] != p && ctr[g + i] && ctr[g + i] != p)
	i++;
	d[h] = malloc((i + 1) * sizeof(char));
	if (!d[h])
	{
	for (i = 0; i < h; i++)
	free(d[i]);
	free(d);
	return (NULL);
	}
	for (j = 0; j < i; j++)
	d[h][j] = ctr[g++];
	d[h][j] = 0;
	}
	d[h] = NULL;
	return (d);
}
