#include "monty.h"

void pall(stack_t **stack)
{
    stack_t *temp = *stack;
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

