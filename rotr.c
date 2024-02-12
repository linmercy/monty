#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        stack_t *last = *stack;
        while (last->next != NULL)
            last = last->next;

        last->next = *stack;
        (*stack)->prev = last;
        *stack = last;
        last->prev->next = NULL;
        last->prev = NULL;
    }
}

