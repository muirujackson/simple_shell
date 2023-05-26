#include "main.h"

/**
 * main - function where the process stsrt
 * @argc: number of argument provide
 * @args: an array of all arguments
 *
 * Return: an int
 */
int main(int argc, char *args[])
{
	int fd = STDIN_FILENO;
	/* determines if input in interactive or from file */
	if (isatty(fd) == 1)
		interactive_mode(args[argc - 1]);
	else
		non_interactive_mode(args[argc - 1]);
	return (0);
}
