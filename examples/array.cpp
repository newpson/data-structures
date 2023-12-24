#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> arr;
	arr.push_back(23);
	for (int i: arr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}
