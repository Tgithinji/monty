#include "monty.h"
#include <stdio.h>

stack_t *temp = NULL;
char **arguments = NULL;
int count = 0;

/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer array containg arguments passed
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t n = 0;
	char *line = NULL;
	unsigned int line_number = 0;
	/* check if number of arguments passed is correct */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open the provided file */
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "ERROR: Can't open fole %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* get each line in the file */
	while (_getline(&line, &n, fd) != -1)
	{
		line_number++;
		/* Remove trailing newline character */
		line[strcspn(line, "\n")] = '\0';
		/* seperate the contnts of line at the given delimeters */
		initialize_args(line);
		if (count == 0)
		{
			continue;
		}
		else
		{
			if (!execute_instruction(line_number))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
				free(line);
				free_arguments();
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_arguments();
	free(line);
	fclose(fd);
	return (0);
}
