#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - program entry point
 * Return: Always 0 when succesful
 */
int main(void)
{
	char line[256];
	unsigned int line_number = 1;
	char *opcode = strtok(line, " \n");
	stack_t *stack = NULL;
	stack_t *current = stack;

	while (fgets(line, sizeof(line), stdin))
	{
		line_number++;

		if (opcode == NULL)
		{
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "Error: Unknown opcode '%s' on line %u\n", opcode, line_number);
			exit(EXIT_FAILURE);
		}
	}
	while (current != NULL)
	{
		stack_t *next = current->next;
		free(current);
		current = next;
	}

	return (0);
}
