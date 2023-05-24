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
 
/*---Macros---*/
#define TOKEN_DELIM " \n\t\r\a\""
extern char **environ;

void interactive_mode(void);
void non_interactive_mode(void);

char* read_line(void);
char **split_strings(char *command);
int env_func(char **args);
int exit_func (char **args);
int execute_command(char **argv);
int system_call(char **args);


#endif
