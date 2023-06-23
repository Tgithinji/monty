#include "monty.h"
/**
 * initialize_args - populates an array with the op_code and argument
 * @line: the buffer containing the content to be seperated
 */
void initialize_args(char *line)
{
	int i = 0, j;
	char *delims = " \n", *token, *line_copy;

	count = 0;
	line_copy = malloc(strlen(line) + 1);

	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_SUCCESS);
	}
	strcpy(line_copy, line); /* get the number of arg */
	token = strtok(line_copy, delims);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delims);
	}
	free_arguments();
	arguments = malloc(sizeof(char *) * (count + 1));
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, line); /* copy arguments to argument array */
	token = strtok(line_copy, delims);
	while (token != NULL)
	{
		arguments[i] = malloc(strlen(token) + 1);
		if (arguments[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failes");
			for (j = 0; j < 1; j++)
			{
				free(arguments[i]);
			}
			free(arguments);
			free(line_copy);
			exit(EXIT_SUCCESS);
		}
		strcpy(arguments[i], token);
		i++;
		token = strtok(NULL, delims);
	}
	arguments[i] = NULL;
	free(line_copy);
}

/**
 * free_arguments - frees memory from arguments array
 */
void free_arguments(void)
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
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &monty_div},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{NULL, NULL}
	};
	if (arguments[0][0] != '#')
		return (_opcode(instructions, line_number));
	return (1);
}

/**
 * _opcode - matches opcode to its respective function
 * @instructions: users instruction
 * @line_number: the number of the line
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

/**
 * is_int - checks if a string is a number
 * @argument: the string
 * Return: 1 if true, 0 if false
 */
int is_int(char *argument)
{
	int i;

	for (i = 0; argument[i] != '\0'; i++)
	{
		/* check if number is negative */
		if (argument[i] == '-' && i == 0)
		{
			continue;
		}
		if (argument[i] < '0' || argument[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
