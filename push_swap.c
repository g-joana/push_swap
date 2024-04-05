#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	nbr;
	int	count;
	int	*numbers;

	nbr = 1;
	count = 0;
	if (argc < 3)
		return 0;
	while (argv[nbr] && nbr < argc)
	{
		numbers[count] = ft_atoi(argv[nbr]);
		nbr++;
		count++;
	}
}
