#include "push_swap.h"

t_stack	*set_stack(int *numbers, int len)
{
	int	i;
	t_node	*node;
	t_stack	*stack;

	i = 0;
	while (i < len)
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			freellist(&node - i, i);
			return (NULL);
		}
		node = node->next;
		i++;
	}
	node = node - i;
	if (!numbers)
	{
		node = NULL;
		stack->len = 0;
		stack->head = node;
		stack->tail = node;
	}
	else
		stack->len = len;
	stack->head = node;
	while(i < len)
	{
		node->value = numbers[i];
		node = node->next;
	}
	node = NULL;
	stack->tail = node;
	return (stack);
}
