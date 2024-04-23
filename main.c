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
	// print_stack(a, 'a');
	// print_stack(b, 'b');
	// printf("\n");
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

int	main(int argc, char **argv)
{
	int	*indexes;
	int	len;
	int	*numbers;
	t_stack	a;
	t_stack	b;

	if (argc <= 2)
		return 0;
	numbers = (int *) malloc((argc - 1) * sizeof(int));
	if (!numbers)
		return (1);
	len = 0;
	while (len < (argc - 1))
	{
		//TODO: tratar max int - min int
		//TODO: validar: se eh td numero,
		numbers[len] = ft_atoi(argv[len + 1]);
		len++;
	}
	// print_int_tab(numbers, len);
	a = set_stack(numbers, len);
	b = set_stack(NULL, 0);
	bubble_sort(numbers, len);
	index_stack(&a, numbers);
	test(&a, &b);
	// order_stack(&a, &b);
	(void) indexes;
	return (0);
}
