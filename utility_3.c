#include "monty.h"

/**
 * _mul - mul the first value in stack to the second value
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = (*stack)->next;
	holder->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - mod the first value in stack to the second value
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->n)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = (*stack)->next;
	holder->n %= (*stack)->n;
	pop(stack, line_number);
}