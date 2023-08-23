#include "shell.h"

/**
* is_cmd - determines if a file is an executable command
* @inf: the info struct
* @path: path to the file
*
* Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *inf, char *path)
{
	struct stat st;

	(void)inf;
	if (!path || stat(path, &st))
	return (0);

	if (st.st_mode & S_IFREG)
	{
	return (1);
	}
	return (0);
}

/**
* cup_chars - duplicates characters
* @pathstr: the PATH string
* @begin: starting index
* @end: stopping index
*
* Return: pointer to new buffer
*/
char *cup_chars(char *pathstr, int begin, int end)
{
	static char buf[1024];
	int l = 0, n = 0;

	for (n = 0, l = begin; l < end; l++)
	if (pathstr[l] != ':')
	buf[n++] = pathstr[l];
	buf[n] = 0;
	return (buf);
}

/**
* find_path - finds this cmd in the PATH string
* @inf: the info struct
* @patstr: the PATH string
* @cmd: the cmd to find
*
* Return: full path of cmd if found or NULL
*/
char *find_path(inf_t *inf, char *patstr, char *cmd)
{
	int l = 0, curr_pos = 0;
	char *pat;

	if (!patstr)
	return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
	if (is_cmd(inf, cmd))
	return (cmd);
	}
	while (1)
	{
	if (!patstr[l] || patstr[l] == ':')
	{
	pat = dup_chars(patstr, curr_pos, l);
	if (!*pat)
	_strcat(pat, cmd);
	else
	{
	_strcat(pat, "/");
	_strcat(pat, cmd);
	}
	if (is_cmd(inf, pat))
	return (pat);
	if (!patstr[l])
	break;
	curr_pos = l;
	}
	l++;
	}
	return (NULL);
}
