#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the top of the stack
 * @line_number: value to push in the stack
 * Return: 0 on success
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (count <= 1 || !(is_int(arguments[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	(*stack)->n = atoi(arguments[1]);
	(*stack)->prev = NULL;
	(*stack)->next = NULL;

	if (temp != NULL)
	{
		(*stack)->next = temp;
		temp->prev = *stack;
	}
	temp = *stack;
}
/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: number of line we are reading
 * Return: 0 on success
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	*stack = temp;
	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to an empty stack
 * @line_number: number of line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stck empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = temp;
	fprintf(stdout, "%d\n", (*stack)->n);
}
