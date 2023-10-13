#ifndef STACK_H
#define STACK_H

typedef struct  stack
{
    int    *data;
    int     size;
    int     length;
}   Stack;

// typedef enum {
//     false = 0,
//     true = 1
// } bool;

Stack   create_stack(int size);
int     empty(Stack *stack);
void    push(Stack *stack, int value);
int     pop(Stack *stack);
int     stack_top(Stack *stack);
void    delete_stack(Stack *stack);

#endif