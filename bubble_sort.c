#include "push_swap.h"

void	bubble_sort(int *numbers, int len)
{
	int	i;
	int	temp;

	i = 0;
	ft_printf("\nbubble\n");
	while (i + 1 < len)
	{
		if (numbers[i] > numbers[i + 1])
		{
			temp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	index_stack(t_stack *stack, int *indexes)
{
	int	count;
	t_node	*node;

	count = 0;
	node = stack->head;
	while (count < stack->len)
	{
		node->index = indexes[count]; // BUG: errado
		node = node->next;
		count++;
	}
}
