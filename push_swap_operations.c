#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	t_node	*temp;
	t_node	*temp2;

	if (a->len <= 1)
		return ;
	temp = pop(a);
	temp2 = pop(a);
	push(temp2, a);
	push(temp, a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int print)
{
	t_node	*temp;
	t_node	*temp2;

	if (b->len <= 1)
		return ;
	temp = pop(b);
	temp2 = pop(b);
	push(temp2, b);
	push(temp, b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->len <= 0)
		return ;
	node = pop(b);
	push(node, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->len <= 0)
		return ;
	node = pop(a);
	push(node, b);
	ft_printf("pb\n");
}
