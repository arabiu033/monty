#include "monty.h"

/**
 * push - push a new node into a stack
 * @stack: working stack
 * @line_number: the line number in the monty file
 * return: a pointer
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	size_t i;
	char *holder;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "%s", "Error: malloc failed\n");
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = strtok(NULL, " ");
	for (i = 0; i < strlen(holder) - 1 || *holder == '\n'; i++)
	{
		if (!isdigit(holder[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(new);
			free_all(*stack, NULL);
			exit(EXIT_FAILURE);
		}
	}

	new->n = atoi(holder);
	new->next = *stack;
	new->prev = NULL;
	*stack = new;

}

/**
 * print - push a new node into a stack
 * @stack: working stack
 * @line_number: the line number in the monty file
 * return: a pointer
 */
void print(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *holder = *stack;

	while (holder)
	{
		printf("%d\n", holder->n);
		holder = holder->next;
	}

}

/**
 * pint - print the first value in stack
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop the first value in stack
 * @stack: the stack
 * @line_number: the line number in the monty file
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(*stack, NULL);
		exit(EXIT_FAILURE);
	}

	holder = *stack;;
	*stack = holder->next;
	free(holder);
}

/**
 * free_list - free linked list
 * @list: list to free
 * Return: nothing
 */
void free_list(stack_t *list)
{
	stack_t *holder;

	while (list)
	{
		holder = list;
		list = list->next;
		free(holder);
	}
}
