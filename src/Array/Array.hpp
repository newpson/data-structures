#pragma once
#include <cstddef>
#include <initializer_list>

template <typename T>
class Array
{
public:
	static std::size_t constexpr DEFAULT_EXPAND_DELTA = 512;
	static std::size_t constexpr DEFAULT_MAX_SIZE = DEFAULT_EXPAND_DELTA;
	const std::size_t expand_delta;

protected:
	std::size_t mmax_size;
	std::size_t msize;
	T *data;
	T *mbegin;
	T *mend;

	Array<T> &expand(std::size_t shift = 0);
	Array<T> &shift_back(T *&pos);

public:
	Array(std::size_t mmax_size = DEFAULT_MAX_SIZE,
			std::size_t expand_delta = DEFAULT_EXPAND_DELTA);
	Array(const std::initializer_list<T> &list,
			std::size_t expand_delta = DEFAULT_EXPAND_DELTA);
	template <std::size_t N>
	Array(const T (&array)[N],
			std::size_t expand_delta = DEFAULT_EXPAND_DELTA);
	Array(const Array &obj);
	~Array();

	Array<T> &operator=(const Array<T> &obj);
	Array<T> &push_back(const T &obj);
	Array<T> &push_front(const T &obj);
	Array<T> &pop_back();
	Array<T> &pop_front();
	Array<T> &shrink();
	Array<T> &insert(T *pos, const T &obj);

	std::size_t size() const;
	std::size_t max_size() const;
	T *begin() const;
	T *end() const;
};

#include "Array.cpp"
