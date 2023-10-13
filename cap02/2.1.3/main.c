#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DATA_LENGTH 10

typedef struct stack
{
    int     size;
    int     head;
    char    *data;
}       Stack;

Stack   create_stack(int);
void    push(Stack*, char);
char    pop(Stack*);
void    compare(char*, Stack*);
void    delete_stack(Stack*);
int     is_empty(Stack*);

int     main(int argc, char **argv)
{
    Stack   stack;
    char    input[DATA_LENGTH];
    int     i;

    assert(argc == 2 && "Use: ./main <string>");
    strcpy(input, argv[1]);
    stack =  create_stack(DATA_LENGTH);
    i = 0;
    while(input[i] != '\0')
    {
        push(&stack, input[i]);
        i++;
    }
    compare(input, &stack);

    delete_stack(&stack);
    return (0);
}

Stack   create_stack(int size)
{
    Stack   stack;

    stack.size = size;
    stack.head = -1;
    stack.data = (char*)malloc(size);
    if (stack.data == NULL)
    {
        fprintf(stderr, "Error in stack.data allocation\n");
        exit(1);
    }
    memset(stack.data, '\0', size);
    return stack;
}

void    push(Stack *stack, char c)
{
    assert(stack->head < (stack->size - 1));
    stack->head++;
    stack->data[stack->head] = c;
}

int     is_empty(Stack *stack)
{
    return (stack->head == -1);
}

char     pop(Stack *stack)
{
    char     r;

    assert(!is_empty(stack) && "Stack empty\n");

    r = stack->data[stack->head];
    stack->data[stack->head] = '\0';
    stack->head--;
    
    return (r);
}

void compare(char *str, Stack *stack)
{
    int     i;

    i = strlen(str) - 1;
    while (str[i] != '\0')
    {
        printf("%c[%c]\n", str[i], pop(stack));
        if (str[i] != pop(stack))
        {
            fprintf(stderr, "Letter doesnt match\n");
            return;
        }
        printf("%c[%c]\n", str[i], pop(stack));
        i--;
    }
}

void    delete_stack(Stack *stack)
{
    free(stack->data);
    stack->head = (-1);
}