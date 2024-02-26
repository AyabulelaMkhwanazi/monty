#include "monty.h"

/**
 * execute_opcodes - execute the given opcode
 *
 * @opcode: the opcode to execute.
 * @arg: the argument to the code.
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: the line number where the opcode is located.
 *
 * Description: This function executes a given opcode with
 *			the given argument. If the opcode is "push",
 *			it checks if the argument is a valid integer
 *			and then calls the push function. For the
 *		other opcodes, it directly calls the corresponding
 *		function. If no match, prints error message.
*/
void execute_opcode(char *opcode, char *arg, stack_t **stack,
unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int n, i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (arg == NULL || !is_integer(arg))
				{
					handle_error(line_number, "usage: push integer");
				}
				n = atoi(arg);
				opcodes[i].f(stack, n);
			}
			else
			{
				opcodes[i].f(stack, line_number);
			}
			return;
		}
		i++;
	}
	/* if no matching opcode was found, print an error */
	handle_error(line_number, "unknown instruction");
}
