#include <stdio.h>

#define SIZE 7

struct Item
{
    int     n;
    int     count;
};


void print_struct(struct Item *itens) 
{
    int     i;

    i = 0;   
    while (i < SIZE)
    {
        printf("Number: %d - ", itens[i].n);
        printf("Count: %d\n", itens[i].count);
        i++;
    } 
}

int     search_moda(struct Item *itens)
{
    int     i;
    int     count_moda;
    int     ctl[2];

    i = 0;
    ctl[0] = itens[i].n;
    ctl[1] = itens[i].count;
    i++;
    while ((i < SIZE) && (itens[i].count > 0))
    {
        if (itens[i].count > ctl[1])
        {
            ctl[0] = itens[i].n;
            ctl[1] = itens[i].count;
        }
        i++;
    }
    i = 0;
    count_moda = 0;
    while (i < SIZE)
    {
        if (itens[i].count == ctl[1])
            count_moda++;
        i++;
    }
    if (count_moda == 1)
        return (ctl[0]);
    else 
        return (-1);
}

int     main(void)
{
    int     i;
    int     j;
    int     flag;
    int     moda;
    int     vector[SIZE] = {8, 5, 2, 1, 2, 1, 1};
    struct  Item itens[SIZE];

    i = 0;
    while (i < SIZE)
    {
        itens[i].n = 0; 
        itens[i].count = 0; 
        i++;
    }
    i = 0;
    itens[0].n = vector[0];
    itens[0].count = 1;
    while (i < SIZE)
    {
        j = 0;
        flag = 0;
        while (j < i)
        {
            if (vector[i] == itens[j].n)
            {
                itens[j].count = itens[j].count + 1;
                flag = 1;
            }
            j++;
        }
        if (flag == 0)
        {
            itens[j].n = vector[i];
            itens[j].count = 1;
        }
        i++;
    }
    print_struct(itens);
    moda  = search_moda(itens); 
    if (moda != (-1))
        printf("Moda is: %d\n", moda);
    else 
        printf("No has moda\n");

    return (0);
}