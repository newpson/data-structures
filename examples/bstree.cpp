#include "BSTree.hpp"
#include <iostream>

int main()
{
	BSTree<int> tree;
	tree.insert(25).insert(23).insert(26);
	for (auto i: tree)
	{
		std::cout << "(" << i.level() << ": " << i.value() << ") ";
	}
	std::cout << std::endl;
	return 0;
}
