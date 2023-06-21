#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer array containg arguments passed
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	(void) argv;
	/* check if number of arguments passed is correct */
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
