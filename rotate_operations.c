#include "push_swap.c"

void	ra(t_stack *a)
{
	t_node	*node;

	node = pop(a);
	push_end(node, a);
}

void	rb(t_stack *b)
{
	t_node	*node;

	node = pop(b);
	push_end(node, b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*node;

	node = pop_end(a);
	push(node, a);
}

void	rrb(t_stack *b)
{
	t_node	*node;

	node = pop_end(b);
	push(node, b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
