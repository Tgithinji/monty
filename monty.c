#include "monty.h"
#include <stdio.h>
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
	int line_number = 1;
	stack_t *stack = malloc(sizeof(stack_t));
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
		line[strcspn(line, "\n")] = '\0';  /* Remove trailing newline character */
		
		if (!execute_instruction(line, &stack, line_number))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			free(line);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		line_number++;

		if (stack == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	/* close file */
	free(line);
	fclose(fd);
	return (0);
}
