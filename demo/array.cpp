#include "array.hpp"
#include <iostream>

int main(void)
{
	arr_t *a = arr_init(3, 3);
	arr_t *b = arr_init(3, 3);

	arr_fill(a);
	arr_fill(b);

	std::cout << "a >>" << std::endl;
	arr_print(a);
	std::cout << "b >>" << std::endl;
	arr_print(b);

	arr_sum(a, b);
	std::cout << "a+b >>" << std::endl;
	arr_print(a);

	arr_t *c = arr_transpose(a);
	std::cout << "aT >>" << std::endl;
	arr_print(c);

	arr_free(a);
	arr_free(b);
	arr_free(c);
	return 0;
}
