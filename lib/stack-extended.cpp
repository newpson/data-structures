#include "stack.hpp"
#include "stack-extended.hpp"
#include <iostream>

void stack_append(node_edu *node, int val)
{
	node_edu *newnode = new node_edu;
	newnode->val = val;
	newnode->next = node->next;
	node->next = newnode;
}

void stack_remove_after(node_edu *node)
{
	node_edu *garbage = node->next;
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

void stack_remove_between(node_edu *na, node_edu *nb)
{
	for (node_edu *cur = na->next; cur != nb; cur = cur->next)
	{
		delete cur;
	}
	na->next = nb;
}

node_edu * stack_find(node_edu *stack, int val)
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

node_edu * stack_find_cmp(node_edu *stack, bool (*cmp)(int a, int b))
{
	node_edu *node_cmp = stack;
	for (; stack; stack = stack->next)
	{
		if (cmp(stack->val, node_cmp->val))
		{
			node_cmp = stack;
		}
	}
	return node_cmp;
}

void stack_swap(node_edu *a, node_edu *b)
{
	if (a != b)
	{
		a->val ^= b->val;
		b->val ^= a->val;
		a->val ^= b->val;
	}
}

void stack_print(stack_edu *stack)
{
	std::cout << "(";
	for (node_edu *node = stack; node; node = node->next)
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
