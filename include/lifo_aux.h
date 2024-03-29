#ifndef _lifo_aux_included_

#include "header.h"

struct lifo_aux
{
    token_t *data;
    struct lifo_aux *next;
};

void push_aux(token_t *data);
token_t *pop_aux(void);
token_t *peek_aux(void);
struct lifo_aux *get_aux_top(void);
void print_aux(void);
int size_aux(void);

#endif
