/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:36:50 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/04 11:44:16 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	void	reverse_rotate(t_Stack *stack)
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

void	rra(t_Stack *stack_a)
{
	printf("rra\n");
	reverse_rotate(stack_a);
}

void	rrb(t_Stack *stack_b)
{
	printf("rrb\n");
	reverse_rotate(stack_b);
}

void	pb(t_Stack *stack_a, t_Stack *stack_b)
{
	int	x;

	printf("pb\n");
	if (!is_empty(stack_a))
	{
		x = pop(stack_a);
		push(stack_b, x);
	}
}

void	pa(t_Stack *stack_a, t_Stack *stack_b)
{
	int	x;

	printf("pa\n");
	if (!is_empty(stack_b))
	{
		x = pop(stack_b);
		push(stack_a, x);
	}
}
