/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:22:56 by jgils             #+#    #+#             */
/*   Updated: 2024/04/30 16:05:03 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	splitlen(char **split)
{
	int	i;

	i = 0;
	while (split && split[i] != NULL)
		i++;
	return (i);
}

char	**splitcat(char **split1, char **split2)
{
	int		i;
	int		is2;
	char	**splitcat;

	i = 0;
	splitcat = (char **)malloc((splitlen(split1) + splitlen(split2) + 1)
			* sizeof(char *));
	while (split1[i] != NULL)
	{
		splitcat[i] = ft_strdup(split1[i]);
		i++;
	}
	is2 = 0;
	while (split2[is2] != NULL)
	{
		splitcat[i + is2] = ft_strdup(split2[is2]);
		is2++;
	}
	splitcat[i + is2] = NULL;
	free_split(split1);
	free_split(split2);
	return (splitcat);
}

long	ft_atol(char *ascii)
{
	int		i;
	int		sig;
	int		count;
	long	nb;

	i = 0;
	sig = 1;
	count = 1;
	nb = 0;
	while ((ascii[i] >= 8 && ascii[i] <= 13) || (ascii[i] == ' '))
		i++;
	while ((ascii[i] == '-' || ascii[i] == '+') && count--)
	{
		if (ascii[i] == '-')
			sig = -1;
		i++;
	}
	while (ascii[i] >= '0' && ascii[i] <= '9')
		nb = nb * 10 + (ascii[i++] - '0');
	return (nb * sig);
}

t_numbers	*set_array(char **split, int count)
{
	int			arg;
	t_numbers	*array;
	long		*numbers;

	numbers = (long *)malloc(count * sizeof(long));
	if (!numbers)
		return (NULL);
	arg = 0;
	while (arg < count)
	{
		numbers[arg] = ft_atol(split[arg]);
		arg++;
	}
	array = (t_numbers *)malloc(sizeof(t_numbers));
	array->numbers = numbers;
	array->len = count;
	free_split(split);
	return (array);
}

t_numbers	*parse_args(int argc, char **argv)
{
	char		**argv_split;
	int			count;
	int			arg;
	t_numbers	*array;

	arg = 1;
	count = count_numbers(argv);
	if (count < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (count == 0)
		exit (1);
	argv_split = ft_split(argv[arg++], ' ');
	while (arg < argc)
	{
		argv_split = splitcat(argv_split, ft_split(argv[arg], ' '));
		arg++;
	}
	array = set_array(argv_split, count);
	return (array);
}
