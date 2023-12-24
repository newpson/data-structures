#include "stack-extended.hpp"
#include <iostream>

bool cmp_max(int a, int b)
{
	return a > b;
}

bool cmp_min(int a, int b)
{
	return a < b;
}

int main(void)
{
	node_edu *stack = stack_init();
	stack_push(stack, 123);
	stack_push(stack, 234);
	stack_push(stack, 345);
	stack_print(stack);
	std::cout << "popped: " << stack_pop(stack) << std::endl;
	std::cout << "popped: " << stack_pop(stack) << std::endl;
	stack_print(stack);
	std::cout << "find 666: " << (stack_find(stack, 666) != NULL) << std::endl;
	stack_push(stack, 666);
	std::cout << "find 666: " << (stack_find(stack, 666) != NULL) << std::endl;
	stack_append(stack_find(stack, 666), 444);
	stack_print(stack);
	stack_swap(stack_find_cmp(stack, cmp_max), stack_find_cmp(stack, cmp_min));
	stack_print(stack);
	stack_free(stack);
	return 0;
}
