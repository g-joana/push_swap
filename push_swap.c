#include "push_swap.h"

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
	int	count;
	int	len;
	int	*numbers;
	t_stack	a;
	// t_stack	b;

	if (argc <= 2)
		return 0;
	len = 1;
	while (argv[len] && len <= argc)
		len++;
	numbers = (int *) malloc(len * sizeof(int));
	if (!numbers)
		return (1);
	count = 0;
	len = 0;
	while (argv[len + 1] && (len + 1) <= argc)
	{
		//TODO: tratar max int - min int
		numbers[count] = ft_atoi(argv[len + 1]);
		// ft_printf("%i\n", numbers[count]);
		len++;
		count++;
	}
	print_int_tab(numbers, len);
	a = *set_stack(numbers, len);
	// b = set_stack();
	index_stack(a.head, a.len, numbers);
	// order_stack(&a, &b);
	return (0);
}
