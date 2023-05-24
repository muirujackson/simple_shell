#include "main.h"

/**
 * system_call - seach the command in system call
 * @args: the command and option
 *
 * Return: integer indication sucess or failure
 */
int system_call(char **args, char *name)
{
	pid_t pid, ended_pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* child process */
		if (execve(args[0], args, environ) == -1)
		{
			perror(name);
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
