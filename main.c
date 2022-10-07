#include "monty.h"

/**
 * main - check the code
 * @ac: args count
 * @av: args passed
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *fd;
	size_t len = 0;
	int read, lineCount = 0;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	line = NULL;
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	free_all(head, fd);
	while ((read = getline(&line, &len, fd)) != -1)
	{
		if (*line == '\n')
		{
			++lineCount;
			continue;
		}
		filter(&head, ++lineCount);
	}

	fclose(fd);
	if (line)
		free(line);
	free_list(head);
	exit(EXIT_SUCCESS);
}

/**
 * filter - filter the function to trigger
 * @stack: the linked list
 * @l: number line
 * Return: void
 */
void filter(stack_t **stack, unsigned int l)
{
	instruction_t ins[] = { {"push", push}, {"pall", print}, {"pint", pint},
				{"pop", pop}, {"add", add}, {"swap", swap}, {"nop", nop},
				{"sub", sub}, {"div", _div}, {"mul", _mul}, {"mod", _mod} };
	char *cmd = strtok(line, " ");
	int i;

	if (*cmd == '\n' || *cmd == '#')
		return;
	for (i = 0; i < 11; i++)
	{
		if (!strncmp(ins[i].opcode, cmd, strlen(cmd) - 1))
		{
			ins[i].f(stack, l);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", l, cmd);
	free_all(*stack, NULL);
	exit(EXIT_FAILURE);
}


/**
 * free_all - free all the memory in use
 * @list: list
 * @f: file descrp
 * Return: void
 */
void free_all(stack_t *list, FILE *f)
{
	static FILE *fd;

	if (f)
	{
		fd = f;
		return;
	}
	fclose(fd);
	free(line);
	free_list(list);
}
