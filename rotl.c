#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *last = *stack;
        while (last->next != NULL)
            last = last->next;

        last->next = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        last->next->prev = last;
        last->next->next = NULL;
    }
}

