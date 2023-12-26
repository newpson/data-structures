#include "AVLTree.hpp"
#include <iostream>

int main()
{

	AVLTree<int> tree;
	tree.insert(25).insert(23).insert(27).insert(24).insert(22).insert(26).insert(28);

	for (auto i: tree.breadthorder())
	{
		std::cout << "(" << i.level() << ": " << i.value() << ") ";
	}
	std::cout << std::endl;

	for (auto i: tree.inorder())
	{
		std::cout << "(" << i.level() << ": " << i.value() << ") ";
	}
	std::cout << std::endl;

	tree.remove(27);
	for (auto i: tree.breadthorder())
	{
		std::cout << "(" << i.level() << ": " << i.value() << ") ";
	}
	std::cout << std::endl;
	return 0;
}
