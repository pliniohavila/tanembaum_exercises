#include <stdio.h>

typedef enum 
{
    false = 0;
    true = 1;
} bool;

typedef struct control
{
    int     size;
    int     count;
    void    (*check)(struct control *self);

}       Control;

bool    check(Control*);
void    push(Control*);
void    pop(Control*);

int     main(void)
{
    Control control;

    control.size = 5;    
    control.count = 0;
    control.check = check;

    push(&control);
    pop(&control);
    pop(&control);

    return (0);
}

void    push(Control *control)
{
    control->check(control);
    control->count++;
}

void    pop(Control *control)
{
    if (control->check(control))
        control->count--;
}


bool    check(Control *self)
{
    if (self->count > (self->size - 1))
    {
        printf("Stack Overflow\n");
        return false;
    }
    if (self->count < 0)
    {
        printf("Stack Underflow\n");
        return false;
    }
    printf("COUNT: %d\n", self->count);
    return true;
}