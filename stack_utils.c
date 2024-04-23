#include "push_swap.h"

t_node	*new_node(int number)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->index = 0;
	node->value = number;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		stack->head = node;
		stack->tail = stack->head;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->len++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return(NULL);
	node = stack->head;
	node->prev = NULL;
	node->next = NULL; // BUG: gera segfault pq node e stack->head sao a mesma memoria, portanto, ao fazer node->next = NULL acontece que stack->head tambem fica = NULL. Temos que fazer isso depois de atualizar a lista
	if (stack->len == 1)
	{
		stack->head = NULL;
		stack->tail = stack->head;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	stack->len--;
	return(node);
}

void	push_end(t_node *node, t_stack *stack)
{
	if (stack->len == 0)
	{
		stack->tail = node;
		stack->head = stack->tail;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->len++;
}

t_node	*pop_end(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return(NULL);
	node = stack->tail;
	node->prev = NULL;
	node->next = NULL;
	if (stack->len == 1)
	{
		stack->tail = NULL;
		stack->head = stack->tail;
	}
	else 
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	stack->len--;
	return(node);
}

void	del_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->head != NULL)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	free(stack);
}

#include <stdio.h>
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
