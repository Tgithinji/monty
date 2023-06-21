#include "monty.h"

/**
 * initialize_args - populates an array with the op_code
 * and argument
 * @line: the buffer containing the content to be seperated
 * @arguments: the array of pointers
 */
void initialize_args(char *line, char ***arguments)
{
	int i = 0, count = 3;
	char *delims = " \n\t", *token, *line_copy;

	line_copy = malloc(strlen(line) + 1);
	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	*arguments = malloc(sizeof(char *) * (count + 1));
	if (*arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(line_copy);
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, line);
	token = strtok(line_copy, delims);
	while (token != NULL)
	{
		(*arguments)[i] = malloc(strlen(token) + 1);
		if ((*arguments)[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failes");
			free_arguments(*arguments);
			free(line_copy);
			exit(EXIT_SUCCESS);
		}
		strcpy((*arguments)[i], token);
		i++;
		token = strtok(NULL, delims);
	}
	(*arguments)[i] = NULL;
	free(line_copy);
}

/**
 * free_arguments - frees memory from arguments array
 * @arguments: array of pointers
 */
void free_arguments(char **arguments)
{
	int i;
	for (i = 0; arguments[i] != NULL; i++)
	{
		free(arguments[i]);
	}
	free(arguments);
}
