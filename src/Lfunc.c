/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 19:28:37 by smagniny         ###   ########.fr       */
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
	new_node->next = stack->top;
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
		stack->top = curr_node;
		prev_node->next = NULL;
	}
}

int	check_asc(t_Stack *stack)
{
	t_Node	*node;

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