
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
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	int		len;
} t_stack;

void	bubble_sort(int *numbers, int count);
t_stack	set_stack(int *numbers, int len);
void	index_stack(t_stack *stack, int *indexes);
t_node	*new_node(int number);
void	push(t_node *node, t_stack *stack);
t_node	*pop(t_stack *stack);
void	del_stack(t_stack *stack);


t_node	*pop_end(t_stack *stack);
void	push_end(t_node *node, t_stack *stack);
void	print_stack(t_stack *a);

#endif
