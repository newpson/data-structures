#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"

typedef node_t queue_t;

node_t * queue_init(void);
void queue_free(queue_t *queue);

void queue_push(queue_t *&queue, int val);
int queue_peek(queue_t *queue);
int queue_pop(queue_t *queue);
bool queue_empty(queue_t *queue);

#endif /* QUEUE_HPP */
