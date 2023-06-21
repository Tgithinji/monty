#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the top of the stack
 * @value: value to push in the stack
 * Return: 0 on success
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * Return: 0 on success
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d%d\n", current->n, line_number);
		current = current->next;
	}
}
