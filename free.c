#include "monty.h"

/**
 * free_stack - function frees a stack.
 *
 * @stack: pointer to pointer to the top of the stack.
 *
 * Description: This function traverses the stack from the
 *			top to the bottom, freeing each node of the stack.
 *			It's used to prevent memory leaks by ensuring that
 *			all memory allocated for the stack is properly
 *			free'd when the stack is no longer needed.
 *
 * Return: void.
*/
void free_stack(stack_t **stack)
{
	stack_t *current_node = *stack;
	stack_t *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
