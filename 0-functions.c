#include "monty.h"

/**
 * is_integer - function checks for an integer.
 *
 * @s: pointer to the integer to check.
 *
 * Return: 1 if it is an integer, else 0.
*/
int is_integer(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
		{
			return (0);
		}
	}
	return (1);
}
