#include "monty.h"
/**
 * nop - function that does nothing
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the nop opcode is
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * sub - function that Subtracts the top element from the second
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the nop opcode is
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	pop(stack, line_number);
}
/**
 * monty_div - function that divides the second top element by the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the nop opcode is
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	pop(stack, line_number);
}
/**
 * mul - function that Multiplies the second top element by the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the nop opcode is
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	pop(stack, line_number);
}
/**
 * mod - function that Computes the remainder of the div
 * ision of the second top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the nop opcode is
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	pop(stack, line_number);
}
