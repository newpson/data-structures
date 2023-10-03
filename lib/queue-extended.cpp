#include "queue.hpp"
#include "queue-extended.hpp"
#include <iostream>

node_t *queue_peek_node(queue_t *tail)
{
	return tail->next;
}

void queue_remove_after(node_t *node)
{
	/* WARN tail deletion is possible */
	node_t *garbage = node->next;
	node->next = garbage->next;
	delete garbage;
}

void queue_print(queue_t *tail)
{
	std::cout << "(";
	for (node_t *node = tail->next;
			node != tail;
			node = node->next)
	{
		std::cout << node->val;
		if (node->next != tail)
		{
			std::cout << ", ";
		}
	}
	std::cout << ")" << std::endl;
	std::cout << std::endl;
}

void queue_roll(queue_t *&tail)
{
	queue_push(tail, queue_pop(tail));
}
