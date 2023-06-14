/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:09:37 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/14 10:58:23 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	ra(t_Stack *stack)
{
	t_Node	*last_node;

	printf("ra\n");
	if (stack->top && stack->top->next)
	{
		last_node = stack->top;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = stack->top;
		stack->top->prev = last_node;
		stack->top = stack->top->next;
		stack->top->prev = NULL;
		last_node->next->next = NULL;
	}
}

void	rb(t_Stack *stack)
{
	t_Node	*last_node;

	printf("rb\n");
	if (stack->top && stack->top->next)
	{
		last_node = stack->top;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = stack->top;
		stack->top->prev = last_node;
		stack->top = stack->top->next;
		stack->top->prev = NULL;
		last_node->next->next = NULL;
	}
}

void	sa(t_Stack *stack)
{
	int	tmp;

	printf("sa\n");
	if (stack->top && stack->top->next)
	{
		tmp = stack->top->data;
		stack->top->data = stack->top->next->data;
		stack->top->next->data = tmp;
	}
}

void	sb(t_Stack *stack)
{
	int	tmp;

	printf("sb\n");
	if (stack->top && stack->top->next)
	{
		tmp = stack->top->data;
		stack->top->data = stack->top->next->data;
		stack->top->next->data = tmp;
	}
}
