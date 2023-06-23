#include "monty.h"

/**
  * add - Adds the top two elements of the stack
  * @stack: Pointer to the top of the stack
  * @line_number: Line number
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the topo of the stack
 * @stack: pointer to a stack
 * @line_number: line number of the opcode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (stack_length == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (char)temp->n);
}

/**
 * pstr - prints the string at the top of a stack
 * @stack: a pointer to a stack
 * @line_number: line_number of the opcode
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) stack;
	(void) line_number;

	current = temp;
	while (current != NULL)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		fprintf(stdout, "%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: points to a stack
 * @line_number: line number of the opcode
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (temp == NULL || temp->next == NULL)
		return;
	(void) stack;
	(void) line_number;

	temp1 = temp;
	temp2 = temp;
	temp = temp->next;
	if (temp != NULL)
		temp->prev = NULL;
	while (temp2->next)
		temp2 = temp2->next;
	temp1->prev = temp2;
	temp2->next = temp1;
	temp1->next = NULL;
}

/**
 * rotr - rotates stack to the bottom
 * @stack: pointer to a stack
 * @line_number: number of the line read
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;

	(void) stack;
	(void) line_number;

	if (temp == NULL)
		return;
	temp1 = temp;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = temp1;
	temp1->prev = temp;
}
