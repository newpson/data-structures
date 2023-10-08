#ifndef STACK_EXTENDED_HPP
#define STACK_EXTENDED_HPP

#include "stack.hpp"

void stack_remove_after(node_edu *node);
void stack_remove_between(node_edu *na, node_edu *nb);
node_edu * stack_find(stack_edu *stack, int val);
node_edu * stack_find_cmp(stack_edu *stack, bool (*cmp)(int a, int b));
void stack_append(node_edu *node, int val);
void stack_swap(node_edu *a, node_edu *b);
void stack_print(stack_edu *stack);

#endif /* STACK_EXTENDED_HPP */
