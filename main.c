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
	interactive_mode(args[argc - 1]);
	return (0);
}
