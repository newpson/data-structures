#ifndef STACK_ARRAY_HPP
#define STACK_ARRAY_HPP

typedef node_t stack_t;

stack_t * stack_init(void);
void stack_free(stack_t *stack);

void stack_push(stack_t *&stack, int val);
int stack_peek(stack_t *stack);
int stack_pop(stack_t *&stack);
bool stack_empty(stack_t *stack);

#endif /* STACK_HPP */
