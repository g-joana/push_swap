#include "push_swap.h"

void	bubble_sort(int *numbers, int count)
{
	int	i;
	int	temp;

	while (i < count)
	{
		if (numbers[i] > numbers[i + 1])
		{
			temp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}
