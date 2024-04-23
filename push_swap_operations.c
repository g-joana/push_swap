#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*temp;
	t_node	*temp2;

	if (a->head == NULL || a->head->next == NULL)
		return ;
	temp = pop(a);
	temp2 = pop(a);
	push(temp2, a);
	push(temp, a);
}

void	sb(t_stack *b)
{
	t_node	*temp;
	t_node	*temp2;

	if (b->head == NULL || b->head->next == NULL)
		return ;
	temp = pop(b);
	temp2 = pop(b);
	push(temp2, b);
	push(temp, b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->head == NULL)
		return ;
	node = pop(a);
	push(node, b);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->head == NULL)
		return ;
	node = pop(b);
	push(node, a);
}
