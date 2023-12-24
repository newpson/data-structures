#pragma once
#include "Array.hpp"
#include <algorithm>
#include <initializer_list>
#include <cstddef>

template <typename T>
Array<T>::Array(std::size_t mmax_size, std::size_t expand_delta):
	expand_delta(expand_delta == 0 ? DEFAULT_EXPAND_DELTA : expand_delta),
	mmax_size(mmax_size == 0 ? DEFAULT_MAX_SIZE : mmax_size),
	msize(0),
	data(new T[mmax_size]),
	mbegin(data),
	mend(mbegin+msize)
{}

template <typename T>
Array<T>::Array(const std::initializer_list<T> &list, std::size_t expand_delta):
	expand_delta(expand_delta == 0 ? DEFAULT_EXPAND_DELTA : expand_delta),
	mmax_size(list.size() == 0 ? DEFAULT_MAX_SIZE : list.size()),
	msize(mmax_size),
	data(new T[mmax_size]),
	mbegin(data),
	mend(mbegin+msize)
{
	std::copy(list.begin(), list.end(), mbegin);
}

template <typename T>
template <std::size_t N>
Array<T>::Array(const T (&array)[N], std::size_t expand_delta):
	expand_delta(expand_delta == 0 ? DEFAULT_EXPAND_DELTA : expand_delta),
	mmax_size(N),
	msize(N),
	data(new T[N]),
	mbegin(data),
	mend(mbegin+msize)
{
	static_assert(N > 0);
	std::copy_n(array, N, mbegin);
}


template <typename T>
Array<T>::Array(const Array<T> &obj):
	expand_delta(obj.expand_delta),
	mmax_size(obj.mmax_size),
	msize(obj.msize),
	data(new T[obj.mmax_size]),
	mbegin(data+(obj.mbegin-obj.data)),
	mend(mbegin+msize)
{
	std::copy(obj.begin(), obj.end(), mbegin);
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
	data = nullptr;
	mbegin = nullptr;
	mend = nullptr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	mmax_size = obj.mmax_size;
	msize = obj.msize;
	delete[] data;
	data = new T[mmax_size];
	mbegin = data+(obj.mbegin-obj.data);
	mend = mbegin+msize;
	std::copy(obj.begin(), obj.end(), mbegin);
	return *this;
}


template <typename T>
Array<T> &Array<T>::push_back(const T &obj)
{
	if (mend == data+mmax_size)
	{
		expand();
	}
	*mend = obj;
	++mend;
	++msize;
	return *this;
}

template <typename T>
Array<T> &Array<T>::push_front(const T &obj)
{
	if (mbegin == data)
	{
		expand(expand_delta);
	}
	--mbegin;
	++msize;
	*mbegin = obj;
	return *this;
}

template <typename T>
Array<T> &Array<T>::pop_back()
{
	--mend;
	--msize;
	return *this;
}

template <typename T>
Array<T> &Array<T>::pop_front()
{
	++mbegin;
	--msize;
	return *this;
}

template <typename T>
Array<T> &Array<T>::insert(T *pos, const T &obj)
{
	if (pos >= mbegin && pos <= mend)
	{
		shift_back(pos);
		*pos = obj;
	}
	return *this;
}

//
// CAPACITY
//

template <typename T>
Array<T> &Array<T>::expand(std::size_t shift)
{
	mmax_size += expand_delta;
	T *_data = new T[mmax_size];
	T *_mbegin = _data+(mbegin-data)+shift;
	std::copy(mbegin, mend, _mbegin);
	mbegin = _mbegin;
	mend = _mbegin+msize;
	delete[] data;
	data = _data;
	return *this;
}

template <typename T>
Array<T> &Array<T>::shift_back(T *&pos)
{
	if (mend == data+mmax_size)
	{
		std::size_t delta = pos-mbegin;
		expand();
		pos = data+delta;
	}
	std::copy_backward(pos, mend, mend+1);
	++mend;
	++msize;
	return *this;
}

template <typename T>
Array<T> &Array<T>::shrink()
{
	mmax_size = msize;
	T *_data = new T[mmax_size];
	std::copy(mbegin, mend, _data);
	mbegin = _data;
	mend = _data+msize;
	delete[] data;
	data = _data;
	return *this;
}

template <typename T>
std::size_t Array<T>::size() const
{
	return msize;
}

template <typename T>
std::size_t Array<T>::max_size() const
{
	return mmax_size;
}

template <typename T>
T *Array<T>::begin() const
{
	return mbegin;
}

template <typename T>
T *Array<T>::end() const
{
	return mend;
}
