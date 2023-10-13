#include <stdio.h>
#include <stdlib.h>
// #include <assert.h>

typedef struct node
{
    char        letter;
    struct node *next;
} Node;


void    create_node(char, Node*);
void    print_stack(Node*);
void    clear_stack(Node*);

int     main(int argc, char **argv)
{
    int     i;
    Node    *head;
    char    *input;    

    if (argc < 2)
    {
        fprintf(stderr, "Use: main [ABABBA]");
        exit(1);
    }
    head = NULL;
    input = argv[1];
    i = 0;
    while (input[i] != '\0')
    {
        create_node(input[i], head);
        i++;
    }
    print_stack(head);
    clear_stack(head);
    print_stack(head);
    return (0);
}

void    create_node(char letter, Node *head)
{
    Node    *node;

    node = (Node*)malloc(sizeof(node));
    if (node == NULL)
    {
        fprintf(stderr, "ERROR: node don't create\n");
        exit(1);
    }
    node->letter = letter;
    if (head == NULL)
    {
        head = node;
    }
    else 
    {
        node->next = head;
        head = node;
    }
    return;
}

void    print_stack(Node *head)
{
    Node    *current;

    if (head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    current = head;
    printf("STACK: ");
    while (current != NULL)
    {
        printf("%c", current->letter);
        current = current->next;
    }
}

void    clear_stack(Node *head)
{
    Node    *current;

    if (head == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    current = head;
    while (head != NULL)
    {
        head = current->next;
        free(current);  
        current = head;
    }
    return;
}