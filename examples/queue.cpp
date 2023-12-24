#include "Queue.hpp"

int main()
{
	Queue<int> queue;
	for (int i = 0; i < 10; ++i)
	{
		queue.push(i);
	}

	while (!queue.empty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop();
	}

	return 0;
}
