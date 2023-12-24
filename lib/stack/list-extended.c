#include "node/list.h"
#include "stack/list.h"
#include "stack/list-extended.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

void stack_insert(node_list_t *node, const void *val)
{
	node_list_t *newnode = malloc(sizeof(node_list_t));
	newnode->val = val;
	newnode->next = node->next;
	node->next = newnode;
}

void stack_remove_after(node_list_t *node)
{
	node_list_t *garbage = node->next;
	node->next = node->next ? node->next->next : NULL;
	free(garbage);
}

void stack_remove_between(node_list_t *nodea, node_list_t *nodeb)
{
	for (node_list_t *cur = nodea->next; cur != nodeb; cur = cur->next)
	{
		free(cur);
	}
	nodea->next = nodeb;
}

void stack_swap(node_list_t *a, node_list_t *b)
{
	if (a->val != b->val)
	{
		a->val = (void *) ((uintptr_t) a->val ^ (uintptr_t) b->val);
		b->val = (void *) ((uintptr_t) b->val ^ (uintptr_t) a->val);
		a->val = (void *) ((uintptr_t) a->val ^ (uintptr_t) b->val);
	}
}

node_list_t *stack_find(stack_t *stack, const void *val,
		bool (*cmp)(const void *vala, const void *valb))
{
	for (node_list_t *cur = stack->head; cur; cur = cur->next)
	{
		/* see qsort() */
		if (!cmp(val, cur->val))
		{
			return cur;
		}
	}
	return NULL;
}


void stack_fprint(FILE *out, void (*fprint)(FILE *out, void *val), stack_t *stack)
{
	fprintf(out, "(");
	for (node_list_t *cur = stack->head; cur; cur = cur->next)
	{
		fprint(cur->val);
		if (cur->next)
		{
			fprintf(out, ", ");
		}
	}
	fprintf(out, ")");
}
