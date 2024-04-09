#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	count;
	int	*numbers;
	// t_stack	a;
	// t_stack	b;

	if (argc <= 2)
		return 0;
	count = 0;
	while (argv[count + 1] && (count + 1) < argc)
		count++;
	numbers = (int *) malloc((count - 1) * sizeof(int));
	if (!numbers)
		return (1);
	count = 0;
	while (argv[count + 1] && (count + 1) < argc)
	{
		// tratar max int - min int
		numbers[count] = ft_atoi(argv[count + 1]);
		count++;
	}
	bubble_sort(numbers, count);
	// a = set_stack(numbers, count);
	// b = set_stack();
	// order_stack(&a, &b);
	return (0);
}
