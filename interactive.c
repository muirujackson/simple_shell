#include "main.h"

/**
 * interactive_mode - function for interactive mode
 * @name: program name
 *
 * Return: void
 */
void interactive_mode(char *name)
{
	char *line;
	char **args;
	int execute_status;

	while (1)
	{
		write(0, "$ ", 2);
		line = read_input();
		args = split_strings(line);
		execute_status = execute_command(args, name);
		if (execute_status >= 0)
		{
			free(line);
			free(args);
			exit(execute_status);
		} else
			continue;
	}
}
