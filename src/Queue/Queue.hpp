#pragma once
#include "SLList.hpp"
#include <cstddef>

template <typename T>
class Queue
{
protected:
	using Node = typename SLList<T>::Node;
	std::size_t msize;
	Node *tail;

public:
	Queue():
		msize(0), tail(new Node())
	{
		tail->next = tail;
	}

	~Queue()
	{
		Node *i = tail;
		do
		{
			Node *garbage = i;
			i = i->next;
			delete garbage;
		}
		while (i != tail);
	}

	Queue &push(const T &value)
	{
		tail->value = value;
		tail->next = new Node(tail->next);
		tail = tail->next;
		++msize;
		return *this;
	}

	const T &front() const
	{
		return tail->next->value;
	}

	Queue &pop()
	{
		Node *garbage = tail->next;
		tail->next = garbage->next;
		delete garbage;
		--msize;
		return *this;
	}

	std::size_t size() const
	{
		return msize;
	}

	bool empty() const
	{
		return msize == 0;
	}
};
