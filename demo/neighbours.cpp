#include "stack-extended.hpp"

int main(void)
{
	node_edu *stack = stack_init();
	stack_push(stack, 123);
	stack_push(stack, 123);
	stack_push(stack, 123);
	stack_push(stack, 123);
	stack_push(stack, 123);

	for (node_edu *node = stack; node; node = node->next)
	{
		if (node->next)
		{
			if (node->next->next)
			{
				if (node->val == node->next->next->val)
				{
					stack_remove_after(node);
				}
			}
		}
	}

	stack_print(stack);
	stack_free(stack);

	return 0;
}
