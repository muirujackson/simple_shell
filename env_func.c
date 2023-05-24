#include "main.h"

/**
 * env_func - enviroment function
 * @args:an array of all variable in string
 *
 * Return: an integer
 */
int env_func(char **args)
{
	int i = 0;
	args = environ;

	while (args[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
