#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "node/list.h"
#include <stdbool.h>

typedef struct
{
	node_list_t *head;
} stack_t;

stack_t *stack_init(void);
void stack_free(stack_t *stack);

void stack_push(stack_t *stack, const void *val);
void *stack_peek(stack_t *stack);
void *stack_pop(stack_t *stack);
bool stack_empty(stack_t *stack);

#endif /* STACK_H */
