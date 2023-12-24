#ifndef STACK_LIST_EXTENDED_H
#define STACK_LIST_EXTENDED_H

#include "node/list.h"
#include "stack/list.h"
#include <stdio.h>
#include <stdbool.h>

void stack_insert(node_list_t *node, const void *val);
void stack_remove_after(node_list_t *node);
void stack_remove_between(node_list_t *nodea, node_list_t *nodeb);
void stack_swap(node_list_t *nodea, node_list_t *nodeb);
node_list_t *stack_find(stack_t *stack, const void *val, bool (*cmp)(const void *vala, const void *valb));

void stack_fprint(FILE *out, void (*fprint)(FILE *out, void *val), stack_t *stack);

#endif /* STACK_LIST_EXTENDED_H */
