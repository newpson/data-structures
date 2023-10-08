#include "queue.hpp"
#include "queue-extended.hpp"
#include <iostream>

node_edu *queue_peek_node(queue_edu *tail)
{
	return tail->next;
}

void queue_remove_after(node_edu *node)
{
	/* WARN tail deletion is possible */
	node_edu *garbage = node->next;
	node->next = garbage->next;
	delete garbage;
}

void queue_print(queue_edu *tail)
{
	std::cout << "(";
	for (node_edu *node = tail->next;
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

void queue_roll(queue_edu *&tail)
{
	queue_push(tail, queue_pop(tail));
}
