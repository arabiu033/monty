#include "monty.h"

/**
 * add - add the first value in stack to the second value
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = (*stack)->next;
	holder->n += (*stack)->n;
	pop(stack, line_number);
}
