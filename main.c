#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL; /* Initialize the stack */

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        char *token = strtok(line, " \n");
        if (token == NULL || strcmp(token, "push") != 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " \n");
        if (token == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(token);
        push(&stack, value);
    }

    fclose(file);
    if (line)
        free(line);

    pall(&stack);

    return 0;
}

