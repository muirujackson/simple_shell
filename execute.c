#include "main.h"

/**
 * execute_command - call the command, check if builtin or system call
 * @argv: tokens to be executed
 *
 * Return: an interger indicating suceess or failure
 */
int execute_command(char **argv)
{
	unsigned long int index;
	char *built_ins_list[] = {
	"exit",
	"env"
	};
	int (*built_ins_function[])(char **) = {
	&exit_func,
	&env_func
	};

	if (!argv)
	{
		/* an empty command was entered */
		return (-1);
	}

	for (index = 0; index < sizeof(built_ins_list) / sizeof(char *); index++)
	{
		/* check if there is a match in the builtins */
		if (strcmp(argv[0], built_ins_list[index]) == 0)
		{
			return ((*built_ins_function[index])(argv));
		}
	}
	/*Create a process to execute */
	return (system_call(argv));
}
