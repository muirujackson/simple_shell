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
	char path[1024], *main_path = getenv("PATH"), *directory;
	int index;

	index = 0;
	/* check if there is a pipe in the command*/
	while (args[index] != NULL)
	{
		if (strcmp(args[index], "|") == 0)
		{
			return (pipe_func(args));
		}
               if (strcmp(args[index], ";") == 0)
                {
                        return (semiColon_func(args));
                }
		index++;
	}

	if (access(args[0], X_OK) == 0)
	{
		return (access_command(args[0], args));
	}


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
			return (access_command(full_path, args));
		}
		directory = strtok(NULL, ":");
	}
	perror(name);
	return (-1);
}
