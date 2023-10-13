#include <stdio.h>
#include <stdlib.h>
#include <assert.h>;
#include "stack.h"

Stack   create_stack(int size)
{
    Stack   stack;

    stack.size = size;
    stack.data = (int*)malloc(size * sizeof(int));
    if (stack.data == NULL)
        exit(EXIT_FAILURE);
    stack.length = 0;

    return (stack);
}

int     empty(Stack *stack)
{
    if (stack->length == 0)
        return (1);
    
    return (0);
}

void    push(Stack *stack, int value)
{
    // assert(stack->length < stack->size);
    if (stack->length == (stack->size - 1))
        fprintf(stderr, "Stack overflow\n");
    stack->data[stack->length] = value;
    stack->length++;
}

int     pop(Stack *stack)
{
    int     i;

    if (empty(stack) == 1)
    {
        fprintf(stderr, "Stack underflow\n");
        return (-1);
    }
    i = stack->data[stack->length - 1];
    stack->length--;
    
    return (i);
}

int     stack_top(Stack *stack)
{
    int     i;

    if (empty(stack) == 1)
        fprintf(stderr, "Stack empty\n");
    i = stack->data[stack->length - 1];
    
    return (i);
}

void    delete_stack(Stack *stack)
{
    free(stack->data);
}