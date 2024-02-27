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

/**
 * nop - Doesn't do anything.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the'nop'
 *			opcode in a Monty bycode file.
 *			The 'nop' opcode doesn't do anything.
 *
 * Return: void.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: The line number where the opcode is located.
 *
 * Description: This function is designed to implement the 'sub' opcode
 *			in a Monty bytecode file.
 *			The 'sub' opcode subtracts the top element of the stack from
 *			the second top element of the stack. If the stack is less
 *			two elements, it prints an error message and exits with
 *			the status EXIT_FAILURE. The result is stored in the
 *			second top element of the stack, and the top element is
 *			removed.
 *
 * Return: void.
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't sub, stack too short", NULL);
	}

	/* Subtract the top element of the stack from the second top element */
	(*stack)->next->n -= (*stack)->n;

	/* remove the top element of the stack */
	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}