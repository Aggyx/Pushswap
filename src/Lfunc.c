/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/15 15:14:55 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	is_empty(t_Stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_Stack *stack, int x)
{
	t_Node	*new_node;

	new_node = (t_Node *)ft_calloc(sizeof(t_Node), 1);
	new_node->data = x;
	new_node->index = -0;
	new_node->prev = NULL;
	new_node->next = stack->top;
	if (stack->top != NULL)
	{
		stack->top->prev = new_node;
	}
	stack->top = new_node;
}

int	pop(t_Stack *stack)
{
	t_Node	*tmp;
	int		x;

	if (is_empty(stack))
	{
		printf("Stack underflow\n");
		exit(1);
	}
	x = stack->top->data;
	tmp = stack->top;
	stack->top = stack->top->next;
	if (stack->top != NULL)
	{
		stack->top->prev = NULL;
	}
	free(tmp);
	return (x);
}

void	reverse_rotate(t_Stack *stack)
{
	t_Node	*prev_node;
	t_Node	*curr_node;

	if (stack->top && stack->top->next)
	{
		prev_node = NULL;
		curr_node = stack->top;
		while (curr_node->next != NULL)
		{
			prev_node = curr_node;
			curr_node = curr_node->next;
		}
		curr_node->next = stack->top;
		stack->top->prev = curr_node;
		stack->top = curr_node;
		prev_node->next = NULL;
		curr_node->prev = NULL;
	}
}

int	check_asc(t_Stack *stack)
{
	t_Node	*node;

	if (lstsize(stack) == 0 || lstsize(stack) == 1)
		return (0);
	node = stack->top;
	while (node->next != NULL && node)
	{
		if (node->data < node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
