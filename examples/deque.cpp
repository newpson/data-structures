#include "Deque.hpp"
#include <iostream>

int main()
{
	Deque<int> queue;
	for (int i = 0; i < 10; ++i)
	{
		queue.push_back(i);
	}

	while (!queue.empty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop_front();
	}

	int a;
	std::cin >> a;
	std::cout << a;

	return 0;
}
