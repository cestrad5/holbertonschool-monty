#include "monty.h"

/**
 * main - main function for Monty ByteCodes files interpreter
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE if the function fails
 */

int main(int argc, char *argv[])
{
    stack_t *tpstack = NULL;
    FILE *file_d;
    char *arg_file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    arg_file = argv[1];
    file_d = fopen(arg_file, "r");
    if (file_d == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", arg_file);
        exit(EXIT_FAILURE);
    }

    get_code(file_d, &tpstack);
    mem_free(tpstack);
    fclose(file_d);

    exit(EXIT_SUCCESS);
}

/**
 * get_code - gets the command
 * @file: file to read to gets the command
 * @tpstack: linear data structure
 *
 * Return: void
 */

void get_code(FILE *file, stack_t **tpstack)
{
    char *opcode, *token = NULL;
    size_t size = 0;
    int counter = 0;

    while (getline(&opcode, &size, file) != -1)
    {
        counter++;
        token = strtok(opcode, "\n\t\r ");
        if (token == NULL || *token == '#')
            continue;

        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, "\n\t\r ");
            push_func(token, tpstack, counter);
        }
        else
            get_func(token, tpstack, counter);
    }

    free(opcode);
}