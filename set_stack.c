#include "push_swap.h"

int	get_maxshift(int number)
{
	int	count;

	count = 0;
	while (number >= 2)
	{
		number >>= 1;
		count++;
	}
	return (count);
}

t_stack	set_stack(long *numbers, int len)
{
	int	i;
	t_node	*node;
	t_stack	stack;

	i = len - 1;
	stack.len = 0;
	stack.head = NULL;
	stack.tail = NULL;
	stack.maxshift = 0;
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
	stack.maxshift = get_maxshift(len - 1);
	return (stack);
}
