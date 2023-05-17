#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	
#define CMD_OR		
 
void interactive_mode(void);
void non_interactive_mode(void);
int hsh(info_t *, char **);
int is_cmd(info_t *, char *);
int loophsh(char **);
int _putchar(char);
int _strcmp(char *, char *);
int _putchar(char);
char *_strchr(char *, char);
void _free(char *);
int _atoi(char *);
int print_d(int, int);
int _help(info_t *);
int replace_alias(info_t *);
char **list_to_strings(list_t *);
#endif
