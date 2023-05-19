/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:36:50 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/19 16:25:33 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

void	swap(t_Stack *stack)
{
	int	tmp;

	if (stack->top && stack->top->next)
	{
		tmp = stack->top->data;
		stack->top->data = stack->top->next->data;
		stack->top->next->data = tmp;
	}
}

void	rotate(t_Stack *stack)
{
	t_Node	*last_node;

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

void	push_a_to_b(t_Stack *stack_a, t_Stack *stack_b)
{
	int	x;

	if (!is_empty(stack_a))
	{
		x = pop(stack_a);
		push(stack_b, x);
	}
}

void	push_b_to_a(t_Stack *stack_a, t_Stack *stack_b)
{
	int	x;

	if (!is_empty(stack_b))
	{
        x = pop(stack_b);
		push(stack_a, x);
	}
}
