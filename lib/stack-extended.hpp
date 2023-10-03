#ifndef STACK_EXTENDED_HPP
#define STACK_EXTENDED_HPP

#include "stack.hpp"

void stack_remove_after(node_t *node);
void stack_remove_between(node_t *na, node_t *nb);
node_t * stack_find(stack_t *stack, int val);
node_t * stack_find_cmp(stack_t *stack, bool (*cmp)(int a, int b));
void stack_append(node_t *node, int val);
void stack_swap(node_t *a, node_t *b);
void stack_print(stack_t *stack);

#endif /* STACK_EXTENDED_HPP */
