#include "monty.h"
#include <stdio.h>

/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer array containg arguments passed
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
	fd = fopen(argv[1], "r"); /* open the provided file */
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (_getline(&line, &n, fd) != -1)/* get each line in the file */
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';/* Remove trailing newline character */
		initialize_args(line);/* seperate the contnts of line */
		if (count == 0)
			continue;
		else
		{
			if (!execute_instruction(line_number))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arguments[0]);
				free(line);
				free_stack();
				free_arguments();
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_arguments();
	free(line);
	free_stack();
	fclose(fd);
	return (0);
}

/**
 * free_stack - free stack memory
 */
void free_stack(void)
{
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		stack_t *temp2 = temp;

		temp = temp->next;
		free(temp2);
	}
}
