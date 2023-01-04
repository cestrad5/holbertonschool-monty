#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: stack
 * @line: line number of the command
 *
 * Return: void
 */

void add_func(stack_t **stack, unsigned int line)
{
	int first;
	int second;
	int result;
	stack_t *top;

	top = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	first = top->n;
	second = top->next->n;
	result = first + second;

	pop_func(stack, line);
	(*stack)->n = result;
}
