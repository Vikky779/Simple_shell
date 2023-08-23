#define _SHELL_H_
#ifndef _SHELL_H_

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* the read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* the command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/* the convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

extern char **environ;


/**
* struct liststr - singly linked list
* @num: the number field
* @str: a string
* @next: points to the next node
*/
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *next;
} list_t;
/**
* struct passinfo - contains pseudo-arguements to pass into a function,
* allowing uniform prototype for function pointer struct
* @arg: a string generated from getline containing arguements
* @argv:an array of strings generated from arg
* @path: a string path for the current command
* @argc: the argument count
* @line_count: the error count
* @err_num: the error code for exit()s
* @linecount_flag: if on count this line of input
* @fname: the program filename
* @env: linked list local copy of environ
* @environ: custom modified copy of environ from LL env
* @events: the history node
* @alias: the alias node
* @env_changed: on if environ was changed
* @status: the return status of the last exec'd command
* @cmd_buf: address of pointer to cmd_buf, on if chaining
* @cmd_buf_type: CMD_type ||, &&, ;
* @readfd: the fd from which to read line input
* @envcount: the history line number count
*/
typedef struct passinfo
{
        char *arg;
        char **argv;
        char *path;
        int argc;
        unsigned int line_count;
        int err_num;
        int linecount_flag;
        char *fname;
        list_t *env;
        list_t *events;
        list_t *alias;
        char **environ;
        int env_changed;
        int status;

        char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
        int cmd_buf_type; /* CMD_type ||, &&, ; */
        int readfd;
       int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
                0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} builtin_table;


/* viay_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* viay_parse.c */
int is_cmd(info_t *, char *);
char *cup_chars(char *, int, int);
char *busc_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* viay_errors.c */
void _errputs(char *);
int _errputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* viay_shell_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* viay_shell_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* viay_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* viay_shell_token.c */
char **strfow(char *, char *);
char **strfow2(char *, char);

/* viay_reallot.c */
char *_memset(char *, char, unsigned int);
void rfree(char **);
void *_reallot(void *, unsigned int, unsigned int);

/* viay_mem.c */
int bfree(void **);

/* viay_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _atoi(char *);
int _isalpha(int);


/* viay_errors1.c */
int _eratoi(char *);
void print_err(info_t *, char *);
int print_f(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* viay_builtin.c */
 int _miexit(info_t *);
int _micd(info_t *);
int _mihelp(info_t *);

/* viay_builtin1.c */
int _myhistory(info_t *);
int _dalias(info_t *);

/*viay_gtline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* viay_acqinfo.c */
void clr_inf(inf_t *);
void set_inf(inf_t *, char **);
void free_inf(inf_t *, int);

/* viay_environ.c */
char *_getenvi(info_t *, const char *);
int _envi(info_t *);
int _setenvi(info_t *);
int _unsetenvi(info_t *);
int populate_envi_list(info_t *);

/* viay_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* viay_events.c */
char *get_events_file(info_t *inf);
int write_events(info_t *inf);
int read_events(info_t *inf);
int build_evenys_list(info_t *inf, char *buf, int linecount);
int renumber_events(info_t *inf);

/* viay_list.c */
list_t *add_sec(list_t **, const char *, int);
list_t *add_sec_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_sec_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* viay_list1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *sec_starts_with(list_t *, char *, char);
ssize_t get_sec_index(list_t *, list_t *);

/* viay_variables.c */
int is_trail(inf_t *, char *, size_t *);
void check_trail(inf_t *, char *, size_t *, size_t, size_t);
int replace_alias(inf_t *);
int replace_var(inf_t *);
int replace_string(char **, char *);

#endif

