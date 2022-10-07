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
 * _mod - mod the first value in stack to the second value
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

/**
 * pchar - pchar the first value in stack
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 126 || (*stack)->n < 21)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - push a new node into a stack
 * @stack: working stack
 * @line_number: the line number in the monty file
 * return: a pointer
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *holder = *stack;

	while (holder && holder->n != 0 && holder->n > 20 && holder->n < 127)
	{
		printf("%c", holder->n);
		holder = holder->next;
	}
	printf("\n");

}
