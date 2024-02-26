#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: value of the new element.
 *
 * Return: void.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	/* allocate memory for a new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		handle_error(line_number, "Error: malloc failed", NULL);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - prints all values on the stack starting from the top of the stack
 *
 * @stack: pointer to pointer to the top of the stack.
 * @line_number: line number
 *
 * Return: void.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
