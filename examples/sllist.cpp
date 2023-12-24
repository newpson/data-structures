#include "SLList.hpp"
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const SLList<T> &list)
{
	for (const T &i: list)
	{
		out << i << " ";
	}
	return out;
}

int main()
{
	SLList<int> list;
	list.push(12).push(23).push(34).push(45).push(56);
	std::cout << list << std::endl;
	auto iter = list.find(34);
	if (iter != SLList<int>::Iterator(nullptr))
	{
		list.pop(iter);
	}
	std::cout << list << std::endl;

	return 0;
}
