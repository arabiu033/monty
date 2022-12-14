#include "monty.h"

/**
 * rotr - push a new node into a stack
 * @stack: working stack
 * @line_number: the line number in the monty file
 * return: a pointer
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *holder = *stack, *dum;

	if (!holder || !holder->next)
		return;

	while (holder && holder->next)
	{
		dum = holder;
		holder = holder->next;
	}

	dum->next = NULL;
	holder->next = *stack;
	holder->prev = NULL;
	*stack = holder;
}
