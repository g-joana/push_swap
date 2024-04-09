
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_number {
	int		index;
	int		value;
	struct s_number	*next;
} t_number;

typedef struct s_stack {
	t_number	*head;
	t_number	*tail;
	int		numbers;
} t_stack;

void	bubble_sort(int *numbers, int count);

#endif
