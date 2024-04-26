/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:21:51 by jgils             #+#    #+#             */
/*   Updated: 2024/04/26 15:23:26 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nbr(char **split, int i, int n)
{
	int	count;

	count = 0;
	if (split[i][n] >= '0' && split[i][n] <= '9' && (split[i][n + 1] == ' '
			|| split[i][n + 1] == '\0'))
		count++;
	if (split[i][n] != ' ' && !(split[i][n] >= '0' && split[i][n] <= '9'))
	{
		if (split[i][n] == '-')
		{
			if (n != 0 && split[i][n - 1] != ' ')
				return (-1);
			if (split[i][n + 1] < '0' || split[i][n + 1] > '9')
				return (-1);
		}
		else
			return (-1);
	}
	return (count);
}

int	count_numbers(char **split)
{
	int	i;
	int	n;
	int	count;
	int	icount;

	i = 0;
	count = 0;
	while (split[++i] != NULL)
	{
		n = 0;
		while (split[i][n] != '\0')
		{
			icount = 0;
			icount = valid_nbr(split, i, n);
			if (icount < 0)
				return (-1);
			count += icount;
			n++;
		}
	}
	return (count);
}

int	validate_values(t_numbers *array)
{
	int	i;
	int	n;

	i = 0;
	while (i < array->len)
	{
		n = 0;
		if (array->numbers[i] > INT_MAX || array->numbers[i] < INT_MIN)
			return (0);
		while (n < array->len)
		{
			if (n == i)
				n++;
			if (n >= array->len)
				break ;
			if (array->numbers[n] == array->numbers[i])
			{
				return (0);
			}
			n++;
		}
		i++;
	}
	return (1);
}
