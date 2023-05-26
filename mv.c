/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:19 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/25 16:51:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

void	initialize(t_Stack *stack)
{
	stack->top = NULL;
}

int	is_empty(t_Stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_Stack *stack, int x)
{
	t_Node	*new_node;

	new_node = (t_Node *)ft_calloc(sizeof(t_Node), 1);
	new_node->data = x;
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

int	peek(t_Stack *stack)
{
	if (is_empty(stack))
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack->top->data);
}
