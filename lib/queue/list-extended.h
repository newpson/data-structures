#ifndef QUEUE_LIST_EXTENDED_H
#define QUEUE_LIST_EXTENDED_H

#include "node/list.h"
#include "queue/list.h"
#include <stdlib.h>
#include <stdio.h>

node_list_t *queue_peek_node(queue_t *queue);
void queue_remove_after(node_list_t *node);
void queue_roll(queue_t *queue);
void queue_fprint(FILE *out, void (*fprint)(FILE *out, void *val), queue_t *queue);

#endif /* QUEUE_LIST_EXTENDED_H */
