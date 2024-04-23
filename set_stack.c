#include "push_swap.h"

t_stack	set_stack(int *numbers, int len)
{
	int	i;
	t_node	*node;
	t_stack	stack;

	i = 0;
	stack.len = 0;
	stack.head = NULL;
	stack.tail = NULL;
	while (i++ < len) // BUG: Index 0 esta sendo pulado
	{
		node = new_node(numbers[i]); // BUG: Ordem de insercao esta errada.
		printf("NEW NODE: %i\n", node->value);
		if (!node)
		{
			del_stack(&stack);
			free(numbers);
			exit(1);
		}
		push(node, &stack);
	}
	return (stack);
}
