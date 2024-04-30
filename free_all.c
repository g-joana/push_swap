/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:23:43 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 14:23:05 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i++]);
	}
	free(split[i]);
	free(split);
}

void	del_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->head != NULL)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
}
