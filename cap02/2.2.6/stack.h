#ifndef STACK_H
#define STACK_H

typedef struct node
{
    int             data;
    struct node    *next;
}       Node;

typedef struct 
{
    int     len;
    Node    *head;
}       Stack;

Stack   *create_stack(void);
void    push(Stack*, int);
int     pop(Stack*);
void    print_stack(Stack*);
void    free_stack(Stack*);

#endif