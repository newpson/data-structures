#include "queue/queue-extended.h"

typedef struct
{
	int a;
	int b;
} hello_t;

int main(void)
{
	queue_t *queue = queue_init(sizeof(int));

	for (int i = 0; i < 10000000; ++i)
	{
		queue_add(queue, &(hello_t){i, i+1});
	}

	for (int i = 0; i < 10000000; ++i)
	{
		queue_poll(queue);
	}

	queue_free(queue);
	return 0;
}
