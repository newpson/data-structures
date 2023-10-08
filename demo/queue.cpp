#include "queue-extended.hpp"

int main(void)
{
	queue_edu *queue = queue_init();

	queue_print(queue);

	queue_push(queue, 1);
	queue_push(queue, 2);
	queue_push(queue, 3);
	queue_print(queue);

	queue_pop(queue);
	queue_pop(queue);
	queue_pop(queue);
	queue_print(queue);

	queue_push(queue, 67);
	queue_push(queue, 68);
	queue_push(queue, 69);
	queue_print(queue);

	queue_pop(queue);
	queue_print(queue);

	queue_free(queue);
	return 0;
}
