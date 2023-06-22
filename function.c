#include "monty.h"
int count;
char **arguments;
stack_t *temp;
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
	stack_t *current;

	(void) line_number;
	(void) stack;

	if (temp == NULL)
		return;

	current = temp;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to an empty stack
 * @line_number: number of line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stck empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", temp->n);
}

/**
 * pop - deletes the top most node
 * @stack: pointer to a stack
 * @line_number: number of line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) stack;
	if (temp == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	current = temp;
	temp = temp->next;
	if (temp != NULL)
		temp->prev = NULL;
	free(current);
}
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the swap opcode is
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the add opcode is
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line_number);
}
