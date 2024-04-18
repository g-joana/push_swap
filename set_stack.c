#include "push_swap.h"

t_stack	set_stack(int *numbers, int len)
{
	int	i;
	t_node	*node;
	t_stack	*stack;

	i = 0;
	node = (t_node *)malloc(len * sizeof(t_node));
	if (!node) //free
		return (NULL);
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
	return (*stack);
}
