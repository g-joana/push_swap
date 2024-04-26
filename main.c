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
	printf("\n");
	// printf("\n");
	// printf("\n");
	(void)a, (void)b;
}


void	print_int_tab(int *numbers, int len)
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

//TODO: validar: num duplicado


int	count_numbers(char **split)
{
	int	i;
	int	n;
	//
	i = 0;
	while (split[++i] != NULL)
	{
		n = 0;
		while (split[i][n] != '\0') 
		{
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
	return (i - 1);
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
	printf("Entrou uma vez\n");
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

int	ft_atol(char *ascii)
{
	int	i;
	int	sig;
	int	count;
	int	nb;
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

t_numbers	*parse_args(int argc, char **argv)
{
	char	**argv_split;
	int	count;
	int	arg;
	int	*numbers;
	t_numbers	*array;
	//"1 2 3" "4 10 15"
	arg = 1;
	count = count_numbers(argv);
	printf("count: %i\n", count);
	if (count < 0)
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
	// set_array();
	numbers = (int *) malloc(count * sizeof(int));
	if (!numbers)
		return (NULL);
	arg = 0;
	print_split(argv_split);
	while (arg < count)
	{
		//TODO: tratar max int - min int
		numbers[arg] = ft_atol(argv_split[arg]);
		arg++;
	}
	//validar: num dup
	array = (t_numbers *)malloc(sizeof(t_numbers));
	array->numbers = numbers;
	array->len = count;
	return (array);
}

//TODO: validar na main argv vazio; ""
int	main(int argc, char **argv)
{
	t_numbers	*array;
	t_stack	a;
	t_stack	b;
	//
	array = parse_args(argc, argv);
	if (!array)
		return (1);
	// print_int_tab(numbers, len);
	a = set_stack(array->numbers, array->len);
	b = set_stack(NULL, 0);
	// test(&a, &b);
	order_stack(&a, &b, array->numbers);
	test(&a, &b);
	// free(numbers);
	// del_stack(&a);
	return (0);
}
