#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *fd;
	size_t len = 0;
	int read;
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

	while ((read = getline(&line, &len, fd)) != -1 && ++lineCount)
		filter(&head, &line, &lineCount);

	fclose(fd);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}


void filter(stack_t **stack, char **line, unsigned int l)
{
	instruction_t ins[] = { {"push", push}, {"pall", print}  };
	char *cmd = strtok(*line, " ");

	for (i = 0; i < 2; i++)
	{
		if (!strcmp(ins[i].opcode, cmd) && ins[i].f(line, l))
			return;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l, cmd);
	free_list(*stack);
	exit(EXIT_FAILURE);
}
