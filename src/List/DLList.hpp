#pragma once
#include <iterator>
#include <cstddef>

template <typename T>
class DLList
{
public:
	struct Node
	{
		Node *prev;
		Node *next;
		T value;

		Node(Node *prev = nullptr, Node *next = nullptr, T value = T()):
			prev(prev), next(next), value(value)
		{}
	};

protected:
	std::size_t msize;
	Node *tail;

public:
	DLList():
		msize(0), tail(new Node())
	{
		tail->prev = tail->next = tail;
	}

	~DLList()
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

	const T &front() const
	{
		return tail->next->value;
	}

	const T &back() const
	{
		return tail->prev->value;
	}

	DLList &push_back(const T &value)
	{
		tail->value = value;
		tail->next = new Node(tail, tail->next);
		tail = tail->next;
		tail->next->prev = tail;
		++msize;
		return *this;
	}

	DLList &push_front(const T &value)
	{
		tail->next = new Node(tail, tail->next, value);
		tail->next->next->prev = tail->next;
		++msize;
		return *this;
	}

	DLList &pop_back()
	{
		Node *garbage = tail;
		garbage->next->prev = garbage->prev;
		tail = garbage->prev;
		tail->next = garbage->next;
		delete garbage;
		--msize;
		return *this;
	}

	DLList &pop_front()
	{
		Node *garbage = tail->next;
		garbage->next->prev = tail;
		tail->next = garbage->next;
		delete garbage;
		--msize;
		return *this;
	}

	class Iterator
	{
		Node *current;

	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using value_type = T;
		using difference_type = std::size_t;
		using pointer = T*;
		using reference = T&;

		Iterator(Node *current): current(current) {}

		Iterator &operator--()
		{
			current = current->prev;
			return *this;
		}

		Iterator &operator++()
		{
			current = current->next;
			return *this;
		}

		value_type operator*() const
		{
			return current->value;
		}

		bool operator!=(const Iterator &iterator) const
		{
			return current != iterator.current;
		}

		explicit operator bool() const
		{
			return current;
		}

		friend class DLList;
	};

	Iterator begin()
	{
		return Iterator(tail->next);
	}

	const Iterator begin() const
	{
		return Iterator(tail->next);
	}

	Iterator end()
	{
		return Iterator(tail);
	}

	const Iterator end() const
	{
		return Iterator(tail);
	}

	Iterator find(const T &value) const
	{
		for (Iterator i = begin(); i != end(); ++i)
		{
			if (*i == value)
			{
				return i;
			}
		}
		return Iterator(nullptr);
	}

	DLList &insert(Iterator i, const T &value)
	{
		Node *node = new Node(i.current->prev, i.current, value);
		i.current->prev->next = node;
		i.current->prev = node;
		i.current = node;
		++msize;
		return *this;
	}

	DLList &pop(Iterator i)
	{
		Node *garbage = i.current;
		garbage->prev->next = garbage->next;
		garbage->next->prev = garbage->prev;
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
