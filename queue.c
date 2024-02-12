#include "monty.h"

void queue(stack_t **stack)
{
    stack_t *temp = *stack;
    stack_t *last = *stack;

    if (temp != NULL)
    {
        while (last->next != NULL)
            last = last->next;

        last->next = temp;
        temp->prev = last;
        *stack = temp->next;
        temp->next = NULL;
        (*stack)->prev = NULL;
    }
}

