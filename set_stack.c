#include "push_swap.h"

t_stack	set_stack(int *numbers, int len)
{
	int	i;
	t_node	*node;
	t_stack	stack;

	i = len - 1;
	stack.len = 0;
	stack.head = NULL;
	stack.tail = NULL;
	while (i >= 0)
	{
		node = new_node(numbers[i]);
		if (!node)
		{
			del_stack(&stack);
			free(numbers);
			exit(1);
		}
		push(node, &stack);
		i--;
	}
	return (stack);
}
