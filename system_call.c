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
	pid_t pid, ended_pid;
	int status;
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
			pid = fork();
			if (pid == 0)
			{
				/* child process */
				if (execve(full_path, args, environ) == -1)
				{
					perror("me");
					return (-1);
				}
			} else if (pid > 0)
			{
				/* parent process */
				ended_pid = waitpid(pid, &status, WUNTRACED);
				if (ended_pid == -1)
				{
					perror("error while waiting for the child process to end");
					return (-1);
				}
			} else
			{
				perror("fork failed");
				return (-1);
			}
			return (-1);
		}
		directory = strtok(NULL, ":");
	}
	perror(name);
	return (-1);
}
