#include "stack.hpp"
#include "stack-extended.hpp"
#include <iostream>

void stack_append(node_t *node, int val)
{
	node_t *newnode = new node_t;
	newnode->val = val;
	newnode->next = node->next;
	node->next = newnode;
}

void stack_remove_after(node_t *node)
{
	node_t *garbage = node->next;
	if (node->next)
	{
		node->next = node->next->next;
	}
	else
	{
		node->next = nullptr;
	}
	delete garbage;
}

void stack_remove_between(node_t *na, node_t *nb)
{
	for (node_t *cur = na->next; cur != nb; cur = cur->next)
	{
		delete cur;
	}
	na->next = nb;
}

node_t * stack_find(node_t *stack, int val)
{
	for (; stack; stack = stack->next)
	{
		if (stack->val == val)
		{
			return stack;
		}
	}
	return nullptr;
}

node_t * stack_find_cmp(node_t *stack, bool (*cmp)(int a, int b))
{
	node_t *node_cmp = stack;
	for (; stack; stack = stack->next)
	{
		if (cmp(stack->val, node_cmp->val))
		{
			node_cmp = stack;
		}
	}
	return node_cmp;
}

void stack_swap(node_t *a, node_t *b)
{
	if (a != b)
	{
		a->val ^= b->val;
		b->val ^= a->val;
		a->val ^= b->val;
	}
}

void stack_print(stack_t *stack)
{
	std::cout << "(";
	for (node_t *node = stack; node; node = node->next)
	{
		std::cout << node->val;
		if (node->next)
		{
			std::cout << ", ";
		}
	}
	std::cout << ")" << std::endl;
	std::cout << std::endl;
}
