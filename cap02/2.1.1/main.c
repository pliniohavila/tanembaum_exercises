#include <stdio.h>
#include <stdlib.h>
#include <assert.h>;
#include "stack.h"

#define STACK_SIZE 5

int     main(void)
{
    Stack   stack;
    
    stack = create_stack(STACK_SIZE);
    assert(empty(&stack) == 1);
    assert(pop(&stack) == -1 && "Stack underflow\n");
    push(&stack, 88);
    push(&stack, 16);
    push(&stack, 32);
    assert(stack_top(&stack) == 32);
    assert(pop(&stack) == 32);
    push(&stack, 12);
    push(&stack, 90);
    // assert(push(&stack, 100) && "Stack overflow\n");

    delete_stack(&stack);
    
    return (0);
}
// tcc stack.c -run main.c
// gcc -g -O stack.c