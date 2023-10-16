#ifndef QUEUE_STACK_DYNARR

#ifdef QUEUE_LIST
#error "Shit"
#endif

#define QUEUE_STACK_DYNARR

#include "node/list.h"
#include "stack/list.h"

typedef struct
{
	size_t count;
	size_t size;
	stack_t 
	node_list_t *head;
	node_list_t *tail;
} queue_t;

queue_t *queue_init();
void queue_free(queue_t *queue);

void queue_add(queue_t *queue, int val);
void *queue_peek(queue_t *queue);
void queue_poll(queue_t *queue);
bool queue_empty(queue_t *queue);

#endif /* QUEUE_STACK_DYNARR */
