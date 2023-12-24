#include "Stack.hpp"
#include <iostream>

int main()
{
	Stack<int> stack;
	stack.push(12).push(23).push(34).push(45).push(56);
	while (!stack.empty())
	{
		std::cout << stack.front();
		stack.pop();
	}

	std::cout << std::endl;
	std::cout << stack.size() << std::endl;

	return 0;
}

