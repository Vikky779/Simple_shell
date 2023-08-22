#include "shell.h"

/**
* get_events_file - gets the history file
* @inf: parameter struct
*
* Return: allocated string containg history file
*/

char *get_events_file(info_t *inf)
{
	char *buff, *dir;

	dir = _getenv(inf, "HOME=");
	if (!dir)
	return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(EVEN_FILE) + 2));
	if (!buff)
	return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, EVEN_FILE);
	return (buff);
}

/**
* write_events - creates a file, or appends to an existing file
* @inf: the parameter struct
*
* Return: 1 on success, else -1
*/
int write_events(info_t *inf)
{
	ssize_t fd;
	char *filename = get_events_file(inf);
	list_t *node = NULL;

	if (!filename)
	return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
	return (-1);
	for (node = inf->events; node; node = node->next)
	{
	_putsfd(node->str, fd);
	_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
* read_events - reads history from file
* @inf: the parameter struct
*
* Return: histcount on success, 0 otherwise
*/
int read_events(info_t *inf)
{
	int p, last = 0, cntlint = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_events_file(inf);

	if (!filename)
	return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
	return (0);
	if (!fstat(fd, &st))
	fsize = st.st_size;
	if (fsize < 2)
	return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
	return (free(buf), 0);
	close(fd);
	for (p = 0; p < fsize; i++)
	if (buf[p] == '\n')
	{
	buf[p] = 0;
	build_events_list(inf, buf + last, cntline++);
	last = p + 1;
	}
	if (last != p)
	build_events_list(inf, buf + last, cntline++);
	free(buf);
	inf->evencount = cntline;
	while (inf->evencount-- >= HIST_MAX)
	delete_node_at_index(&(inf->events), 0);
	renumber_events(inf);
	return (inf->evencount);
}

/**
* build_events_list - adds entry to a history linked list
* @inf: Structure containing potential arguments. Used to maintain
* @buf: buffer
* @linecount: the history linecount, histcount
*
* Return: Always 0
*/
int build_events_list(info_t *inf, char *buf, int linecount)
{
	list_t *node = NULL;

	if (inf->events)
	node = inf->events;
	add_node_end(&node, buf, linecount);

	if (!inf->events)
	inf->events = node;
	return (0);
}

/**
* renumber_events - renumbers the history linked list after changes
* @inf: Structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int renumber_events(info_t *inf)
{
	list_t *node = inf->events;
	int p = 0;

	while (node)
	{
	node->num = p++;
	node = node->next;
	}
	return (inf->evencount = p);
}


