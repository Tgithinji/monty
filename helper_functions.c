#include "monty.h"

/**
 * initialize_args - populates an array with the op_code
 * and argument
 * @line: the buffer containing the content to be seperated
 * @count: the number of arguments
 */
void initialize_args(char *line)
{
	int i = 0;
	char *delims = " \n\t", *token;
	count = 0;

	/* get the number of arguments in the line buffer */
	token = strtok(line, delims);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delims);
	}
	arguments = malloc(sizeof(char *) * (count + 1));
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/* copy arguments to argument array */
	token = strtok(line, delims);
	while (token != NULL)
	{
		arguments[i] = malloc(strlen(token) + 1);
		if (arguments[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failes");
			free_arguments();
			exit(EXIT_SUCCESS);
		}
		strcpy(arguments[i], token);
		i++;
		token = strtok(NULL, delims);
	}
	arguments[i] = NULL;
}

/**
 * free_arguments - frees memory from arguments array
 * @arguments: array of pointers
 */
void free_arguments()
{
	int i;

	if (arguments == NULL)
	{
		return;
	}

	for (i = 0; arguments[i] != NULL; i++)
	{
		free(arguments[i]);
	}
	free(arguments);
	arguments = NULL;
}

/**
 * execute_instruction - initializes an structure array
 * @line_number: line number
 *
 * Return: 1 for success and 0 for failure
 */
int execute_instruction(unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};
	return (_opcode(instructions, line_number));
}

/**
 * _opcode - matches opcode to its respective function
 * @inst: an structure array
 * @line_number: the number of the line
 *
 * Return: 1 for success and 0 for failure
 */
int _opcode(instruction_t instructions[], unsigned int line_number)
{
	int i;
	stack_t *stack = NULL;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguments[0]) == 0)
		{
			instructions[i].f(&stack, line_number);
			return (1);
		}
	}
	return (0);
}
