#include "stack.hpp"

stack_t * stack_init(void)
{
	stack_t *stack = nullptr;
	return stack;
}

void stack_free(stack_t *stack)
{
	while (stack)
	{
		node_t *garbage = stack;
		stack = stack->next;
		delete garbage;
	}
}

void stack_push(stack_t *&stack, int val)
{
	node_t *node = new node_t;
	node->val = val;
	node->next = stack;
	stack = node;
}

int stack_peek(stack_t *stack)
{
	return stack->val;
}

int stack_pop(stack_t *&stack)
{
	int val = stack->val;
	node_t *garbage = stack;
	stack = stack->next;
	delete garbage;
	return val;
}

bool stack_empty(stack_t *stack)
{
	return stack == nullptr;
}
