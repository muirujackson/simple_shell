#include "main.h"

/**
 * exit_func - exit the shell
 * @args: an array of command
 *
 * Return: an interger
 */
int exit_func(char **args)
{
	/* exit with status */
	if (args[1])
	{
		return (atoi(args[1]));
	}
	/* exit success */
	else
	{
		return (0);
	}
}

