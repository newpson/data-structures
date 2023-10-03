#include <iostream>
#include "stack.hpp"
#include "queue-extended.hpp"

int main(void)
{
	stack_t *burgers = stack_init();
	queue_t *students = queue_init();

	int count;
	std::cin >> count;

	/* student preferences */
	for (int i = 0, input; i < count; ++i)
	{
		std::cin >> input;
		queue_push(students, input);
	}

	/* available burgers */
	for (int i = 0, input; i < count; ++i)
	{
		std::cin >> input;
		stack_push(burgers, input);
	}

	int denied = 0;
	while (denied < count)
	{
		if (queue_peek(students) == stack_peek(burgers))
		{
			queue_pop(students);
			stack_pop(burgers);
			denied = 0;
			--count;
		}
		else
		{
			++denied;
			queue_roll(students);
		}
	}

	std::cout << count << std::endl;

	stack_free(burgers);
	queue_free(students);
	return 0;
}
