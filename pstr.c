#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *temp = *stack;
    while (temp != NULL && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
    {
        printf("%c", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

