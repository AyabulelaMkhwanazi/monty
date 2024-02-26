#include "monty.h"

/**
 * main - main function for the monty code.
 *
 * @argc: argument count (counts the number of arguments supplied.)
 * @argv: argument vectore (array of arguments supplied.)
 * Description: testing the monty codes.
 *
 * Return: always 0.
*/
int main(int argc, char **argv)
{
	char *line = NULL, *opcode, *arg;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *file;
	stack_t *stack = NULL;

	/* check if the correct number of arguments was passed. */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* open the Monty bycode file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Parse the file and execute the opcodes */
	while ((read = getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
		{
			continue;
		}
		arg = strtok(NULL, " \t\n");
		line_number++;
		execute_opcode(opcode, arg, &stack, line_number);
	}
	free(line);
	free_stack(&stack);

	/* close the file */
	fclose(file);
	return (EXIT_SUCCESS);
}
