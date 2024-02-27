#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *		of the stack by the top element.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'mod'
 *			opcode in a Monty bytecode file.
 *			The 'mod' opcode computes the rest of the division
 *			of the second top element of the stack by the top
 *			element of the stack. If the stack contains less
 *			than two elements, it prints an error message and
 *			exits with the status EXIT_FAILURE. If the top
 *			element of the stack is 0, it prints an error
 *			message and exits with the status EXIT_FAILURE.
 *			The result is stored in the second top element
 *			of the stack, and the top element is removed.
 *
 * Return: void.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't mod, stack too short", NULL);
	}

	/* check if the top element of the stack is 0 */
	if ((*stack)->n == 0)
	{
		handle_error(line_number, "division by zero", NULL);
	}

	/* COMPUTE THE REST OF THE DIVISION OF THE SECOND TOP ELEMENT BY */
	/* THE TOP ELEMENT */
	(*stack)->next->n %= (*stack)->n;

	/* remove the top element of the stack */
	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
