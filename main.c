#include <stdio.h>
#include "main.h"

/**
 * main - function where the process stsrt
 * @argc: number of argument provide
 * @argv: an array of all arguments
 *
 * Return: an int
 */
int main(int argc,char *argv[])
{
	/* determines if input in interactive or from file */
	if (isatty(fd) == 1)
		interactive_mode();
	else
		non_interactive_mode();	
	return (0);
}
