/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:10:55 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 15:36:31 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_numbers	*array;
	t_stack		a;
	t_stack		b;

	array = parse_args(argc, argv);
	if (!array)
		return (1);
	if (!validate_values(array))
	{
		free(array->numbers);
		free(array);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = set_stack(array->numbers, array->len);
	b = set_stack(NULL, 0);
	order_stack(&a, &b, array->numbers);
	free(array->numbers);
	free(array);
	del_stack(&a);
	return (0);
}
