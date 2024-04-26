
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_numbers {
	long	*numbers;
	int	len;
} t_numbers;

typedef struct s_node {
	int		index;
	int		value;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	int	maxshift;
	t_node	*head;
	t_node	*tail;
	int		len;
} t_stack;

void	bubble_sort(long *numbers, int count);
t_stack	set_stack(long *numbers, int len);
void	index_stack(t_stack *stack, long *indexes);
t_node	*new_node(long number);
void	push(t_node *node, t_stack *stack);
t_node	*pop(t_stack *stack);
void	del_stack(t_stack *stack);


int	get_maxshift(int number);
t_node	*pop_end(t_stack *stack);
void	push_end(t_node *node, t_stack *stack);
void	print_stack(t_stack *stack, char c);
void	print_int_tab(long *numbers, int len);
void	order_stack(t_stack *a, t_stack *b, long *numbers);
void	order_stack(t_stack *a, t_stack *b, long *numbers);
void	order2(t_stack *a);
void	order3(t_stack *a);
int	absolute(int nbr);
void	order5(t_stack *a, t_stack *b);
void	test(t_stack *a, t_stack *b);
void	radix(t_stack *a, t_stack *b);

void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

#endif
