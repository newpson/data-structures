#include "DLList.hpp"
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
	for (const T &value: list)
	{
		out << value << " ";
	}
	return out;
}

int main()
{
	DLList<int> list;

	list.push_front(23).push_front(22).push_front(21);
	std::cout << list << std::endl;

	list.pop_front().pop_front();
	std::cout << list << std::endl;

	list.push_back(24).push_back(25).push_back(26);
	std::cout << list << std::endl;

	list.pop_back().pop_front();
	std::cout << list << std::endl;

	auto i = list.find(25);
	if (i)
	{
		list.insert(i, 77);
	}
	std::cout << list << std::endl;

	i = list.find(77);
	if (i)
	{
		list.pop(i);
	}
	std::cout << list << std::endl;

	return 0;
}
