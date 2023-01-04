#include "monty.h"

/**
 * get_func - gets the function
 * @opcode: requested function
 * @cp_stack: linear data structure
 * @line: line number
 *
 * Return: function pointer or EXIT_FAILURE if it fails
 */

void get_func(char *opcode, stack_t **cp_stack, unsigned int line)
{
    int index = 0;

    instruction_t function[] = {
        {"pall", pall_func},
        {"pint", pint_func},
        {"pop", pop_func},
        {"swap", swap_func},
        {"add", add_func},
        {"nop", nop_func},
        {NULL, NULL}};

    while (function[index].opcode)
    {
        if (strcmp(function[index].opcode, opcode) == 0)
        {
            function[index].f(cp_stack, line);
            break;
        }
        index++;
    }

    if (function[index].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
        exit(EXIT_FAILURE);
    }
}

/**
 * mem_free - free stack memory
 * @head: pointer to the top of the stack
 *
 * Return: void
 */

void mem_free(stack_t *head)
{
    stack_t *temp;

    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * push_func - pushes an element to the stack
 * @opcode: pointer to the string
 * @top_stack: linear data structure
 * @line: number of the line of the command
 *
 * Return: void
 */

void push_func(char *opcode, stack_t **top_stack, unsigned int line)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
        return;
    }
    if (_isnumber(opcode) == 1 && opcode != NULL)
    {
        new->n = atoi(opcode);
        new->next = *top_stack;
        new->prev = NULL;
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }
    if (*top_stack != NULL)
        (*top_stack)->prev = new;
    *top_stack = new;
}

/**
 * pall_func - prints all the values on the stack
 * @sstack: linear data structure
 * @line: unused attribute
 *
 * Return: void
 */

void pall_func(stack_t **sstack, unsigned int __attribute__((unused)) line)
{
    int index = 0;
    stack_t *current;

    current = *sstack;

    while (current)
    {
        if (current != NULL)
            printf("%d\n", current->n);
        index++;
        current = current->next;
    }
}

/**
 * _isnumber - checks for numbers
 * @opcode: string to check
 *
 * Return: 1 if true, 0 otherwise
 */

int _isnumber(char *opcode)
{
    unsigned int index = 0;

    if (opcode == NULL)
        return (0);

    while (opcode[index])
    {
        if (opcode[0] == '-')
        {
            index++;
            continue;
        }
        if (!isdigit(opcode[index]))
            return (0);
        index++;
    }
    return (1);
}