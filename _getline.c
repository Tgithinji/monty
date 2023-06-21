#include "monty.h"

ssize_t _getl(char **line, size_t *n, FILE *fd);
/**
 * _getline - reads a single line in a stream
 * @line: where to store the read line
 * @n: size of the buffer
 * @fd: the stream the line is to be read from
 *
 * Return: number of lines read
 */
ssize_t _getline(char **line, size_t *n, FILE *fd)
{
	if (*n == 0)
		*n = 20;
	if (*line == NULL)
	{
		*line = malloc(*n);
		if (*line == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			return (-1);
		}
	}

	return (_getl(line, n, fd));
}

/**
 * _getl - loops to the end of the line
 * @line: where the line will be stored
 * @n: points to the size of line
 * @fd: file stream
 *
 * Return: number of chars read
 */
ssize_t _getl(char **line, size_t *n, FILE *fd)
{
	size_t i;
	char ch = '\0';

	for (i = 0; ch != '\n'; i++)
	{
		ch = fgetc(fd);
		if (ch == EOF)
		{
			if (i == 0)
				return (-1);
			break;
		}
		if ((i + 1) >= *n)
		{
			*n *= 2;
			*line = realloc(*line, *n);
			if (*line == NULL)
			{
				fprintf(stderr, "Realloc failed");
				return (-1);
			}
		}
		(*line)[i] = ch;
	}
	(*line)[i] = '\0';
	i = (ssize_t) i;
	return (i);
}
