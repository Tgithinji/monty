#include "monty.h"

int queue_tru = 0;

/**
 * queue - sets the format data to queue
 * @stack: pointer to a stack
 * @line_numbe: line number of the opcode
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	queue_tru = 1;
}

/**
 * satck - sets the format data to stack
 * @stack: pointer to a stack
 * @line_number: line number of the opcode
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	queue_tru = 0;
}
