/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:09:37 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 16:30:20 by smagniny         ###   ########.fr       */
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
		{
			last_node = last_node->next;
		}
		last_node->next = stack->top;
		stack->top = stack->top->next;
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
		stack->top = stack->top->next;
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
