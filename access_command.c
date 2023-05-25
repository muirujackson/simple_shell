#include "main.h"

/**
 * access_command - access command
 * @full_path: path to system call
 * @args: arguments to the command
 *
 * Return: int
 */
int access_command(char *full_path, char **args)
{

	pid_t pid, ended_pid;
	int status;
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
		/*parent process */
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
