#include "push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	t_node	*tmp;

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

	i = 0;
	n = 0;
	while (split[i] != NULL)
	{
		while (split[i][n] != '\0')
		{
			if (split[i][n] < '0' && split[i][n] > '9')
				return (-i);
			n++;
		}
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char	**argv_split;
	int	len;
	int	*numbers;
	t_stack	a;
	t_stack	b;
	int	count;

	count = 1;
	while (count <= argc)
	{
		// argv_split = ft_split(argv[1], ' ');
		splitcat(argv_split, ft_split(argv[count], ' '));
		len = count_numbers(argv_split);
	}
	if (len < 2)
		return 0;
	if (len < 0)
	{
		free_split(argv_split);
		perror("Error");
		return (1);
	}
	numbers = (int *) malloc(len * sizeof(int));
	if (!numbers)
		return (1);
	count = 0;
	while (count < len)
	{
		//TODO: tratar max int - min int
		//TODO: validar: se eh td numero,
		numbers[count] = ft_atoi(argv_split[count + 1]);
		count++;
	}
	// print_int_tab(numbers, len);
	a = set_stack(numbers, len);
	b = set_stack(NULL, 0);
	// test(&a, &b);
	order_stack(&a, &b, numbers);
	test(&a, &b);
	// free(numbers);
	// del_stack(&a);
	return (0);
}
