/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:15:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 19:32:43 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static void	filter_a(t_Stack *stack_a, int *x)
{
	if (stack_a->top->data > stack_a->top->next->data)
	{
		sa(stack_a);
		x++;
	}
	else if (lastelem(stack_a)->data < stack_a->top->data)
	{
		rra(stack_a);
		x++;
	}
	else if (lastelem(stack_a)->data < stack_a->top->next->data && \
		lastelem(stack_a)->data > stack_a->top->data)
	{
		rra(stack_a);
		x++;
		sa(stack_a);
		x++;
	}
}

static void	filter_b(t_Stack *b, int *x)
{
	if (lastelem(b)->data > b->top->data)
	{
		rb(b);
		x++;
	}
	else if (b->top->data < b->top->next->data)
	{
		if (lastelem(b)->data < b->top->next->data && !check_desc(b))
		{
			rrb(b);
			x++;
		}
		if (b->top->data < b->top->next->data)
		{
			sb(b);
			x++;
		}
	}
}

static	int	filter(t_Stack *stack_a, t_Stack *stack_b, int *mouvs)
{
	int	x;

	x = 0;
	mouvs = 0;
	filter_a(stack_a, &x);
	if (lstsize(stack_b) > 1)
		filter_b(stack_b, &x);
	mouvs += x;
	return (*mouvs);
}

void	chainfilter(t_Stack *stack_a, t_Stack *stack_b)
{
	int		mouvs;
	int		flag;

	mouvs = 0;
	flag = 1;
	if (stack_a->top->next == NULL)
		return ;
	while (flag)
	{
		while (filter(stack_a, stack_b, &mouvs))
			;
		if (!check_asc(stack_a))
		{
			pb(stack_a, stack_b);
			mouvs++;
		}
		if (check_asc(stack_a) && lstsize(stack_b) && check_desc(stack_b))
			pa(stack_a, stack_b);
		if (check_asc(stack_a) && !lstsize(stack_b))
			flag = 0;
	}
}