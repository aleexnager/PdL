#include "lifo.h"
#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct lifo *top = NULL;
int stack_size = 0;

void push(token_t *data)
{
    struct lifo *new = (struct lifo *)malloc(sizeof(struct lifo));
    new->data = data;
    new->next = top;
    if (top == NULL)
        new->next = NULL;
    else
        new->next = top;

    ++stack_size;
    top = new;
}

token_t *pop(void)
{
    if (top == NULL)
        exit(-1);

    struct lifo *item = top;
    token_t *data = top->data;
    top = top->next;
    free(item);
    --stack_size;
    return data;
}

struct lifo *get_top(void)
{
    return top;
}

token_t *peek(void)
{
    return top->data;
}

void print(void)
{
    struct lifo *cur;
    cur = top;
    printf("Stack:\n");
    while (cur != NULL)
    {
        printf("%d\n-\n", cur->data->id);
        cur = cur->next;
    }
    printf("\n");
}

int size(void)
{
    return stack_size;
}
