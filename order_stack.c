/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:11:05 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 14:04:24 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_stack *a, t_stack *b, long *numbers)
{
	if (a->len == 2)
	{
		order2(a);
		return ;
	}
	bubble_sort(numbers, a->len);
	index_stack(a, numbers);
	if (is_ordered(a))
		return ;
	if (a->len == 3)
		order3(a);
	else if (a->len == 5 || a->len == 4)
		order5(a, b);
	else
		radix(a, b);
}

void	order2(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		sa(a, 1);
}

int	get_highest(t_stack *a)
{
	int		highest;
	t_node	*node;

	highest = -1;
	node = a->head;
	while (node != NULL)
	{
		if (node->index > highest)
			highest = node->index;
		node = node->next;
	}
	return (highest);
}

void	order3(t_stack *a)
{
	int	highest;

	highest = get_highest(a);
	if (a->head->index == highest)
		ra(a, 1);
	else if (a->head->next->index == highest)
		rra(a, 1);
	if (a->head->index > a->head->next->index)
		sa(a, 1);
}

void	order5(t_stack *a, t_stack *b)
{
	int	lowest;
	int	len;

	lowest = 0;
	len = a->len;
	while (a->len > 3)
	{
		if (a->head->index == 0 || (len == 5 && a->head->index == 1))
		{
			pb(a, b);
			lowest++;
		}
		else
			ra(a, 1);
	}
	order3(a);
	if (b->len == 2 && b->head->index < b->head->next->index)
		sb(b, 1);
	pa(a, b);
	pa(a, b);
}
