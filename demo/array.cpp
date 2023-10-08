#include "array.hpp"
#include <iostream>

int main(void)
{
	arr_edu *a = arr_init(3, 3);
	arr_edu *b = arr_init(3, 3);

	arr_fill(a);
	arr_fill(b);

	std::cout << "a >>" << std::endl;
	arr_print(a);
	std::cout << "b >>" << std::endl;
	arr_print(b);

	arr_sum(a, b);
	std::cout << "a+b >>" << std::endl;
	arr_print(a);

	arr_edu *c = arr_eduranspose(a);
	std::cout << "aT >>" << std::endl;
	arr_print(c);

	arr_free(a);
	arr_free(b);
	arr_free(c);
	return 0;
}
