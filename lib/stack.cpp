#include "stack.hpp"

stack_edu * stack_init(void)
{
	stack_edu *stack = nullptr;
	return stack;
}

void stack_free(stack_edu *stack)
{
	while (stack)
	{
		node_edu *garbage = stack;
		stack = stack->next;
		delete garbage;
	}
}

void stack_push(stack_edu *&stack, int val)
{
	node_edu *node = new node_edu;
	node->val = val;
	node->next = stack;
	stack = node;
}

int stack_peek(stack_edu *stack)
{
	return stack->val;
}

int stack_pop(stack_edu *&stack)
{
	int val = stack->val;
	node_edu *garbage = stack;
	stack = stack->next;
	delete garbage;
	return val;
}

bool stack_empty(stack_edu *stack)
{
	return stack == nullptr;
}
