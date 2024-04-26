/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:11:18 by jgils             #+#    #+#             */
/*   Updated: 2024/04/26 15:11:18 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack *a)
{
	t_node	*node;

	node = a->head;
	while (node != NULL)
	{
		if (node->next == NULL)
			break ;
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

void	radix(t_stack *a, t_stack *b)
{
	int	i;
	int	len;
	int	shift;

	shift = 0;
	len = a->len;
	while (shift <= a->maxshift)
	{
		i = 0;
		while (i++ < len)
		{
			if (a->head->index & (1 << shift))
				ra(a, 1);
			else
				pb(a, b);
		}
		while (b->len > 0)
			pa(a, b);
		shift++;
	}
}
