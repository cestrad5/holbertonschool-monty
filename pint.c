#include "monty.h"

/**
 * pint_func - prints the value at the top of the stack
 * @sstack: name of the stack
 * @line: line number of the command
 *
 * Return: void
 */

void pint_func(stack_t **sstack, unsigned int line)
{
    stack_t *current;

    current = *sstack;

    if (!sstack || !*sstack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", current->n);
}