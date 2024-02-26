#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'add'
 *			opcode in a Monty bytecode file.
 *			The 'add' opcode adds the top two elements of the stack.
 *			If the stack contains less than 2 elements, it prints
 *			an error message and exits with status EXIT_FAILURE.
 *			THE RESULT IS STORED IN THE SECOND TOP ELEMENT OF THE
 *			STACK, AND THE TOP ELEMENT IS REMOVED.
 *
 * Return: void.
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* check if the stack contains less than 2 elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't add, stack too short", NULL);
	}

	/* ADD THE TOP TWO ELEMENTS OF THE STACK */
	(*stack)->next->n += (*stack)->n;

	/* REMOVE THE TOP ELEMENTS OF THE STACK */
	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
