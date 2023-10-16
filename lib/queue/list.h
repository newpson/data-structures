#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "node/list.h"
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
	size_t width;
	node_list_t *tail;
} queue_t;

queue_t *queue_init(size_t width);
void queue_free(queue_t *queue);

void queue_add(queue_t *queue, void *val);
void *queue_peek(queue_t *queue);
void queue_poll(queue_t *queue);
bool queue_empty(queue_t *queue);

#endif /* QUEUE_LIST_H */
