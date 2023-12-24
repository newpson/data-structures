#include "node/list.h"
#include "queue/list.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

queue_t *queue_init(size_t width)
{
	queue_t *queue = malloc(sizeof(queue_t));
	queue->width = width;
	queue->tail = malloc(sizeof(node_list_t));
	queue->tail->val = NULL;
	queue->tail->next = queue->tail;
	return queue;
}

void queue_free(queue_t *queue)
{
	if (queue)
	{
		node_list_t *cur = queue->tail;
		do
		{
			node_list_t *garbage = cur;
			cur = cur->next;
			free(garbage->val);
			free(garbage);
		}
		while (cur != queue->tail);
		free(queue);
	}
}

void queue_add(queue_t *queue, void *val)
{
	queue->tail->val = malloc(queue->width);
	memcpy(queue->tail->val, val, queue->width);
	node_list_t *newtail = malloc(sizeof(node_list_t));
	newtail->val = NULL;
	newtail->next = queue->tail->next;
	queue->tail->next = newtail;
	queue->tail = newtail;
}

void *queue_peek(queue_t *queue)
{
	return queue->tail->next->val;
}

void queue_poll(queue_t *queue)
{
	node_list_t *garbage = queue->tail->next;
	queue->tail->next = garbage->next;
	free(garbage->val);
	free(garbage);
}

bool queue_empty(queue_t *queue)
{
	return queue->tail->next == queue->tail;
}
