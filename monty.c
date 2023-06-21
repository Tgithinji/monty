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
	int fd;
	/* check if number of arguments passed is correct */
	if (argc < 2)
	{
		fprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open the provided file */
	fd = open(filename, 0_RDONLY);
	if (fd == -1)
	return (0);
}
