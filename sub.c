#include "monty.h"
/**
 * sub - subtracts the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n -= (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}