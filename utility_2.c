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

/**
 * nop - dont do anything
 * @stack: working stack
 * @line_number: the line number in the monty file
 * return: a pointer
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
}

/**
 * swap - swap the first value in stack to the second value
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = (*stack)->next;
	tmp = (*stack)->n;
	(*stack)->n = holder->n;
	holder->n = tmp;
}
