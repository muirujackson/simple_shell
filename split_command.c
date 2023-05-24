#include "main.h"

/**
 * split_strings - this fuction tokinezes string and added into an array
 * @line: comand in the string
 *
 * Return: an array of string
 */
char **split_strings(char *line)
{
	int buffer_size = 64;
	int index = 0;
	char *token;
	char **tokens;

	tokens = malloc(buffer_size * sizeof(char *));

	if (!tokens)
	{
		/* memory allocation through malloc failled*/
		perror("memory allocation of tokens");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);

	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		if (index >= buffer_size)
		{
			buffer_size += buffer_size;
			tokens = realloc(tokens, buffer_size * sizeof(char *));

			if (tokens == NULL)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}
