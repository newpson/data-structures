#pragma once
#include "SLList.hpp"

template <typename T>
class Stack: protected SLList<T>
{
public:
	Stack(): SLList<T>()
	{}

	using SLList<T>::push;
	using SLList<T>::front;
	using SLList<T>::pop;
	using SLList<T>::empty;
	using SLList<T>::size;
};
