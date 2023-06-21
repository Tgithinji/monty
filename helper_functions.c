#include "monty.h"

/**
 * initialize_args - populates an array with the op_code
 * and argument
 * @line: the buffer containing the content to be seperated
 * @count: the number of arguments
 * @arguments: the array of pointers
 */
void initialize_args(char *line, char ***arguments, int *count)
{
	int i = 0;
	char *delims = " \n\t", *token;

	/* get the number of arguments in the line buffer */
	token = strtok(line, delims);
	while (token != NULL)
	{
		*count += 1;
		token = strtok(NULL, delims);
	}
	*arguments = malloc(sizeof(char *) * (*count + 1));
	if (*arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/* copy arguments to argument array */
	token = strtok(line, delims);
	while (token != NULL)
	{
		(*arguments)[i] = malloc(strlen(token) + 1);
		if ((*arguments)[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failes");
			free_arguments(arguments);
			exit(EXIT_SUCCESS);
		}
		strcpy((*arguments)[i], token);
		i++;
		token = strtok(NULL, delims);
	}
	(*arguments)[i] = NULL;
}

/**
 * free_arguments - frees memory from arguments array
 * @arguments: array of pointers
 */
void free_arguments(char ***arguments)
{
	int i;

	for (i = 0; (*arguments)[i] != NULL; i++)
	{
		free(*arguments[i]);
	}
	free(*arguments);
}

/**
 * execute_instruction - initializes an structure array
 * @arguments: array of pointers
 * @line_number: line number
 *
 * Return: 1 for success and 0 for failure
 */
int execute_instruction(char **arguments, unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};
	return (_opcode(inst, arguments, line_number));
}

/**
 * _opcode - matches opcode to its respective function
 * @inst: an structure array
 * @arguments: an array of pointers
 * @line_number: the number of the line
 *
 * Return: 1 for success and 0 for failure
 */
int _opcode(instruction_t inst[], char **arguments, unsigned int line_number)
{
	int i;
	stack_t *stack = NULL;

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(inst[i].opcode, arguments[0]) == 0)
		{
			inst[i].f(&stack, line_number);
			return (1);
		}
	}
	return (0);
}
