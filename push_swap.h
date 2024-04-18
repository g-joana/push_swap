
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_node {
	int		index;
	int		value;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	int		len;
} t_stack;

void	bubble_sort(int *numbers, int count);
t_stack	set_stack(int *numbers, int len);
void	index_stack(t_node *stack, int len, int *indexes);

#endif
