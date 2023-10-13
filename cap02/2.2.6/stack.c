#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

Stack   *create_stack(void)
{
    Stack   *stack;

    stack = (Stack*)malloc(sizeof(stack));
    stack->len = -1;
    stack->head = NULL;
    return (stack);
}

void    push(Stack *stack, int value)
{
    Node    *new_node;

    assert(stack != NULL);
    new_node = (Node*)malloc(sizeof(Node));
    assert(new_node != NULL);
    new_node->data = value;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->len++;
}

int     pop(Stack   *stack)
{
    Node    *tmp;
    int     r;

    if (stack->head == NULL || stack->len == (-1))
    {
        fprintf(stderr, "Stack Underflow\n");
        exit(1);
    }
    r = stack->head->data;
    tmp = stack->head->next;
    free(stack->head);
    stack->head = tmp;
    stack->len--;
    return (r);
}

void    print_stack(Stack *stack)
{
    Node    *cur;

    if (stack->head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    assert(stack != NULL);
    cur = stack->head;
    printf("STACK: ");
    while (cur != NULL)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void    free_stack(Stack *stack)
{
    Node    *cur;

    assert(stack != NULL);
    cur = stack->head;
    while (cur != NULL)
    {
        stack->head = stack->head->next;
        free(cur);
        cur = stack->head;
    }
    stack->len = -1;
}