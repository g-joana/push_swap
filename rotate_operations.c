/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:11:22 by jgils             #+#    #+#             */
/*   Updated: 2024/04/26 15:11:22 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	t_node	*node;

	if (a->len <= 1)
		return ;
	node = pop(a);
	push_end(node, a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int print)
{
	t_node	*node;

	if (b->len <= 1)
		return ;
	node = pop(b);
	push_end(node, b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rb(b, 0);
	ra(a, 0);
	ft_printf("rr\n");
}

void	rra(t_stack *a, int print)
{
	t_node	*node;

	if (a->len <= 1)
		return ;
	node = pop_end(a);
	push(node, a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int print)
{
	t_node	*node;

	if (b->len <= 1)
		return ;
	node = pop_end(b);
	push(node, b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rrb(b, 0);
	rra(a, 0);
	ft_printf("rrr\n");
}
