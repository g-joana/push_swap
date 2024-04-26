
#include "push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	t_node	*tmp;
	//
	printf("------------------------------------------\n");
	printf("Stack: %c\n", c);
	tmp = stack->head;
	while(tmp)
	{
		printf("nbr: %i | index: %i\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("------------------------------------------\n");
}

void	test(t_stack *a, t_stack *b)
{
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// print_stack(a, 'a');
	// rra(a, 1);
	print_stack(a, 'a');
	// print_stack(b, 'b');
	// printf("\n");
	// printf("\n");
	(void)a, (void)b;
}


void	print_int_tab(long *numbers, int len)
{
	int	i;
	//
	i = 0;
	while (i < len)
	{
		ft_printf("%i ", numbers[i]);
		i++;
	}
	ft_printf("\n");
}

int	count_numbers(char **split)
{
	int	i;
	int	n;
	int	count;
	//
	i = 0;
	count = 0;
	while (split[++i] != NULL)
	{
		n = 0;
		while (split[i][n] != '\0') 
		{
			if (split[i][n] >= '0' && split[i][n] <= '9' && (split[i][n + 1] == ' ' || split[i][n + 1] == '\0'))
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
			n++;
		}
	}
	return (count);
}

int	splitlen(char **split)
{
	int	i;
	//
	i = 0;
	while (split && split[i] != NULL)
		i++;
	return (i);

}

char	*strmcat(char *s1, char *s2)
{
	int	i;
	int	is2;
	char	*strmcat;
	//
	strmcat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	while (s1[i] != '\0')
	{
		strmcat[i] = s1[i];
		i++;
	}
	is2 = 0;
	while (s2[i] != '\0')
	{
		strmcat[i + is2] = s2[is2];
		is2++;
	}
	strmcat[i + is2] = '\0';
	free(s1);
	free(s2);
	return (strmcat);
}

void	free_split(char **split)
{
	int	i;
	//
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i++]);
	}
	free(split[i]);
	free(split);
}

char	**splitcat(char **split1, char **split2)
{
	int	i;
	int	is2;
	char	**splitcat;
	//
	i = 0;
	splitcat = (char **)malloc((splitlen(split1) + splitlen(split2) + 1) * sizeof(char *));
	// printf("split begins\n");
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
	int	i;
	int	sig;
	int	count;
	long	nb;
	//
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

void	print_split(char **splited)
{
	int	i;

	i = -1;
	printf("------------------------------------\n");
	if (!splited)
	{
		printf("(null)\n");
	}
	while(splited[++i])
		printf("splited[%i] = %s\n",i, splited[i]);
	printf("------------------------------------\n");
}

t_numbers	*set_array(char **split, int count)
{
	int		arg;
	t_numbers	*array;
	long		*numbers;
	//
	numbers = (long *) malloc(count * sizeof(long));
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
	return (array);
}

t_numbers	*parse_args(int argc, char **argv)
{
	char	**argv_split;
	int	count;
	int	arg;
	// long	*numbers;
	t_numbers	*array;
	//
	arg = 1;
	count = count_numbers(argv);
	printf("Count: %i\n", count);
	if (count <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (count < 2)
		exit (0);
	argv_split = ft_split(argv[arg++], ' ');
	while (arg < argc)
	{
		argv_split = splitcat(argv_split, ft_split(argv[arg], ' '));
		arg++;
	}
	array = set_array(argv_split, count);
	// numbers = (long *) malloc(count * sizeof(long));
	// if (!numbers)
	// 	return (NULL);
	// arg = 0;
	// print_split(argv_split);
	// while (arg < count)
	// {
	// 	numbers[arg] = ft_atol(argv_split[arg]);
	// 	arg++;
	// }
	// array = (t_numbers *)malloc(sizeof(t_numbers));
	// array->numbers = numbers;
	// array->len = count;
	return (array);
}

int	validate_values(t_numbers *array)
{
	int	i;
	int	n;
	//
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
				break;
			if (array->numbers[n] == array->numbers[i])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_numbers	*array;
	t_stack	a;
	t_stack	b;
	//
	array = parse_args(argc, argv);
	if (!array)
		return (1);
	if (!validate_values(array))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = set_stack(array->numbers, array->len);
	b = set_stack(NULL, 0);
	order_stack(&a, &b, array->numbers);
	// test(&a, &b);
	// free(numbers);
	// del_stack(&a);
	return (0);
}
