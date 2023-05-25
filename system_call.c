#include "main.h"

/**
 * system_call - seach the command in system call
 * @args: the command and option
 * @name: program name
 *
 * Return: integer indication sucess or failure
 */
int system_call(char **args, char *name)
{
	char path[1024];

	/* Get enviment variable */
	char *main_path = getenv("PATH");
	char *directory;

	strcpy(path, main_path);
	directory = strtok(path, ":");

	while (directory != NULL)
	{
		char full_path[256];
		strcpy(full_path, directory);
		strcat(full_path, "/");
		strcat(full_path, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			return(access_command(full_path, args));
		}
		directory = strtok(NULL, ":");
	}
	perror(name);
	return (-1);
}
