#include "main.h"

/**
 * read_line - function that read line
 *
 * Return: a string
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	bytes_read = getline(&buffer, &buffer_size, stdin);

	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		} else
		{
			free(buffer);
			/* Error occurred while reading the line */
			perror("Error reading standard input");
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
}
