#include "node/list.h"
#include "stack/list.h"
#include <stddef.h>
#include <stdlib.h>

stack_t *stack_init(void)
{
	stack_t *stack = malloc(sizeof(stack_t));
	stack->head = NULL;
	return stack;
}

void stack_free(stack_t *stack)
{
	if (stack)
	{
		while (stack->head)
		{
			node_list_t *garbage = stack->head;
			stack->head = stack->next;
			free(garbage);
		}
		free(stack);
	}
}

void stack_push(stack_t *stack, const void *val)
{
	node_list_t *node = malloc(sizeof(node_list_t));
	node->val = val;
	node->next = stack->head;
	stack->head = node;
}

void *stack_peek(stack_t *stack)
{
	return stack->head->val;
}

void *stack_pop(stack_t *stack)
{
	node_list_t *garbage = stack->head;
	void *val = garbage->val;
	stack->head = stack->head->next;
	free(garbage);
	return val;
}

bool stack_empty(stack_t *stack)
{
	return stack->head == NULL;
}
