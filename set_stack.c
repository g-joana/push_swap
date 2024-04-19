#include "push_swap.h"

t_stack	*set_stack(int *numbers, int len)
{
	int	i;
	t_node	*node;
	t_node	*head;
	t_stack	*stack;

	i = 0;
	//TODO: malocar essa merda
	//TODO: colocar em outra func
	//TODO: fazer funcoes de lista com t_node e free
	while (i++ < len)
	{
		node = new_node();
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			ft_lstclear_bonus(&head, free);
			return (NULL);
		}
		ft_lstadd_back_bonus(&head, node);
	}
	if (!numbers)
	{
		head = NULL;
		stack->len = 0;
		stack->head = head;
		stack->tail = head;
		return (stack);
	}
	stack->len = len;
	stack->head = head;
	i = 0;
	while(i < len)
	{
		node->value = numbers[i++];
		node = node->next;
	}
	node = NULL;
	stack->tail = node;
	return (stack);
}
