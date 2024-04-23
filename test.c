#include "push_swap.h"
#include <stdio.h>

void	test(t_stack *a, t_stack *b)
{
	
}

void	print_stack(t_stack *a)
{
	t_node *tmp;

	tmp = a->head;
	printf("--------------------\n");
	while(tmp)
	{
		printf("%i\n", tmp->value);
		tmp = tmp->next;
	}
	printf("--------------------\n");
}
