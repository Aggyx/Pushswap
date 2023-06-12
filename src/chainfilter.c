/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainfilter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:15:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/12 12:46:03 by smagniny         ###   ########.fr       */
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

static	int	filter(t_Stack *stack_a, t_Stack *stack_b)
{
	int		x;
	t_Stack	*tmp;

	x = 0;
	tmp = cpystack(stack_b);
	filter_a(stack_a, &x);
	if (lstsize(tmp) > 1)
		filter_b(stack_b, &x);
	freestack(tmp);
	return (x);
}

void	chainfilter(t_Stack *stack_a, t_Stack *stack_b)
{
	int		flag;

	flag = 1;
	if (stack_a->top->next == NULL)
		return ;
	while (flag)
	{
		while (filter(stack_a, stack_b))
			;
		if (!check_asc(stack_a))
			pb(stack_a, stack_b);
		if (check_asc(stack_a) && lstsize(stack_b) && check_desc(stack_b))
			pa(stack_a, stack_b);
		if (check_asc(stack_a) && !lstsize(stack_b))
			flag = 0;
	}
}