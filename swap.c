#include "monty.h"

/**
 * swap_func - swaps the top two elements of the stack
 * @stack: stack of elements
 * @line: line number of the command
 *
 * Return: void
 */

void swap_func(stack_t **stack, unsigned int line)
{
    stack_t *current;
    stack_t *node;

    current = *stack;
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line);
        exit(EXIT_FAILURE);
    }

    node = current->next;
    current->next = node->next;
    node->next = *stack;
    current->prev = node;
    node->prev = NULL;
    *stack = node;
}