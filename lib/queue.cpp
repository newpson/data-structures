#include "queue.hpp"

node_edu * queue_init(void)
{
	/* ghost tail */
	queue_edu *tail = new queue_edu;
	tail->next = tail;
	return tail;
}

void queue_free(queue_edu *tail)
{
	node_edu *cur = tail;
	do
	{
		node_edu *garbage = cur;
		cur = cur->next;
		delete garbage;
	}
	while (cur != tail);
}

void queue_push(queue_edu *&tail, int val)
{
	tail->val = val;
	node_edu *newtail = new node_edu;
	newtail->next = tail->next;
	tail->next = newtail;
	tail = newtail;
}

int queue_peek(queue_edu *tail)
{
	return tail->next->val;
}

int queue_pop(queue_edu *tail)
{
	node_edu *garbage = tail->next;
	int val = garbage->val;
	tail->next = garbage->next;
	delete garbage;
	return val;
}

bool queue_empty(queue_edu *tail)
{
	return tail->next == tail;
}
