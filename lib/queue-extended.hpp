#ifndef QUEUE_EXTENDED_HPP
#define QUEUE_EXTENDED_HPP

#include "queue.hpp"

node_edu * queue_peek_node(queue_edu *queue);
void queue_remove_after(node_edu *node);
void queue_roll(queue_edu *&queue);
void queue_print(node_edu *tail);

#endif /* QUEUE_EXTENDED_HPP */
