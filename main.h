#ifndef MAIN_H_
#define MAIN_H_


#define MAX_ARGS 64
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

/*---Macros---*/
#define TOKEN_DELIM " \n\t\r\a\""
extern char **environ;

void interactive_mode(char *name);
void non_interactive_mode(char *name);
int cd_func(char **args);
char *read_line(void);
char **split_strings(char *command);
int env_func(char **args);
int exit_func(char **args);
int execute_command(char **argv, char *name);
int system_call(char **args, char *name);
int access_command(char *full_path, char **args);
char *read_input(void);
int pipe_func(char *args[]);
int semiColon_func(char *args[]);

#endif
