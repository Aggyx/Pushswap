/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:36:50 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 16:30:24 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

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
