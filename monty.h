#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list implementation of
 * a stack or a queue
 * @n: integer
 * @prev: points to the previous element of the stack
 * or queue
 * @next: points to the next elemnt of the stack or
 * queue
 *
 * Descrition: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stacks,
 * queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* global variables */
extern char **arguments;
extern int count;
extern stack_t *temp;

/* function prototypes */
ssize_t _getline(char **line, size_t *n, FILE *fd);
void initialize_args(char *line);
void free_arguments();
int execute_instruction(unsigned int line_number);
int _opcode(instruction_t instructions[], unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int is_int(char *argument);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
