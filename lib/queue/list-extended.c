#include "node/list.h"
#include "queue/list.h"
#include "queue/list-extended.h"
#include <stdlib.h>

node_list_t *queue_peek_node(queue_t *queue)
{
	return queue->tail->next;
}

void queue_remove_after(node_list_t *node)
{
	/* WARN tail deletion is possible */
	node_list_t *garbage = node->next;
	node->next = garbage->next;
	free(garbage->val);
	free(garbage);
}

void queue_roll(queue_t *queue)
{
	void *val = queue_peek(queue);
	queue_add(queue, val);
	queue_poll(queue);
}

void queue_fprint(FILE *out, void (*fprint)(FILE *out, void *val), queue_t *queue)
{
	fprintf(out, "(");
	for (node_list_t *cur = queue_peek_node(queue); cur != queue->tail; cur = cur->next)
	{
		fprint(out, cur->val);
		if (cur->next != queue->tail)
		{
			fprintf(out, ", ");
		}
	}
	fprintf(out, ")");
}
