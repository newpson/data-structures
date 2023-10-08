#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"

typedef node_edu queue_edu;

node_edu * queue_init(void);
void queue_free(queue_edu *queue);

void queue_push(queue_edu *&queue, int val);
int queue_peek(queue_edu *queue);
int queue_pop(queue_edu *queue);
bool queue_empty(queue_edu *queue);

#endif /* QUEUE_HPP */
