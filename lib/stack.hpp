#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"

typedef node_edu stack_edu;

stack_edu * stack_init(void);
void stack_free(stack_edu *stack);

void stack_push(stack_edu *&stack, int val);
int stack_peek(stack_edu *stack);
int stack_pop(stack_edu *&stack);
bool stack_empty(stack_edu *stack);

#endif /* STACK_HPP */
