#include "queue.hpp"

node_t * queue_init(void)
{
	/* ghost tail */
	queue_t *tail = new queue_t;
	tail->next = tail;
	return tail;
}

void queue_free(queue_t *tail)
{
	node_t *cur = tail;
	do
	{
		node_t *garbage = cur;
		cur = cur->next;
		delete garbage;
	}
	while (cur != tail);
}

void queue_push(queue_t *&tail, int val)
{
	tail->val = val;
	node_t *newtail = new node_t;
	newtail->next = tail->next;
	tail->next = newtail;
	tail = newtail;
}

int queue_peek(queue_t *tail)
{
	return tail->next->val;
}

int queue_pop(queue_t *tail)
{
	node_t *garbage = tail->next;
	int val = garbage->val;
	tail->next = garbage->next;
	delete garbage;
	return val;
}

bool queue_empty(queue_t *tail)
{
	return tail->next == tail;
}
