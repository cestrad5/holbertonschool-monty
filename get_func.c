#include "monty.h"

/**
 * get_method - function to get method
 *
 * @method: name of the method
 * Return:  0
 */
void (*get_method(char *method))(stack_t **stack, unsigned int line_number)
{
    instruction_t methods[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"add", add},
        {"swap", swap},
        {"sub", sub},
        {NULL, NULL},
    };

    int i = 0;

    while (methods[i].opcode != NULL)
    {
        if (strcmp(methods[i].opcode, method) == 0)
            return (methods[i].f);
        i++;
    }
    return (NULL);
}