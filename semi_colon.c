#include "main.h"

/**
 * executeCommand - function
 * @commandArgs: args
 *
 * Return: void
 */
void executeCommand(char **commandArgs)
{
	execvp(commandArgs[0], commandArgs);
	perror("Execution of command failed");
	exit(EXIT_FAILURE);
}

/**
 * pipe_func - function
 * @args: arguments
 *
 * Return: int
 */
int pipe_func(char *args[])
{
	int i, j, secondCommandArgCount;
	pid_t child1, child2;
	char **firstCommandArgs = NULL;
	char **secondCommandArgs = NULL;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], ";") == 0)
		{
			args[i] = NULL;
			break;
		}
	}
	firstCommandArgs = malloc((i + 1) * sizeof(char *));
	if (firstCommandArgs == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < i; j++)
	{
		firstCommandArgs[j] = args[j];
	}
	firstCommandArgs[i] = NULL;
	
	secondCommandArgCount = 0;
	for (; args[i + secondCommandArgCount + 1] != NULL; secondCommandArgCount++)
	{
	}
	
	secondCommandArgs = malloc((secondCommandArgCount + 1) * sizeof(char *));
	if (secondCommandArgs == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < secondCommandArgCount; j++)
	{
		secondCommandArgs[j] = args[i + j + 1];
	}
	secondCommandArgs[secondCommandArgCount] = NULL;

	child1 = fork();
	if (child1 < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child1 == 0)
	{
		executeCommand(firstCommandArgs);
	}
	child2 = fork();
	if (child2 < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child2 == 0)
	{
		executeCommand(secondCommandArgs);
		fprintf(stderr, "No second command provided\n");
		exit(EXIT_FAILURE);
	} else if (child2 > 0)
	{

		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);

		free(firstCommandArgs);
		free(secondCommandArgs);
	}
	return (-1);
}
