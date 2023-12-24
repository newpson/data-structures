#pragma once
#include "DLList.hpp"

template <typename T>
class Deque: protected DLList<T>
{
public:
	Deque():
		DLList<T>()
	{}

	using DLList<T>::push_front;
	using DLList<T>::push_back;
	using DLList<T>::front;
	using DLList<T>::back;
	using DLList<T>::pop_front;
	using DLList<T>::pop_back;
	using DLList<T>::empty;
	using DLList<T>::size;
};
