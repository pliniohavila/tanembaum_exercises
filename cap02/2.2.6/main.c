#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int     main(void)
{
    Stack   *stack;
    int     i;
    int     data[5] = {12, 5, 4, 3, 8};

    stack = create_stack();
    i = 0;
    while (data[i])
        push(stack, data[i++]);
    print_stack(stack);
    printf("POP: %d\n", pop(stack));
    printf("POP: %d\n", pop(stack));
    print_stack(stack);
    free_stack(stack);
    print_stack(stack);
    free(stack);
    return (0);
}

