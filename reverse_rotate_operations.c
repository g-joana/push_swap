/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:07:32 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 14:07:32 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
