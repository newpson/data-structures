#ifndef QUEUE_EXTENDED_HPP
#define QUEUE_EXTENDED_HPP

#include "queue.hpp"

node_t * queue_peek_node(queue_t *queue);
void queue_remove_after(node_t *node);
void queue_roll(queue_t *&queue);
void queue_print(node_t *tail);

#endif /* QUEUE_EXTENDED_HPP */
