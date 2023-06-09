/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainfactory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:19:04 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/09 17:20:30 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	int	filter(t_Stack *stack_a, t_Stack *stack_b, int *mouvs)
{
	int	x;

	x = 0;
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
	if (lstsize(stack_b) > 1)
	{	
		if (lastelem(stack_b)->data > stack_b->top->data)
		{
			rb(stack_b);
			x++;
		}
		else if (stack_b->top->data < stack_b->top->next->data)
		{
			if (lastelem(stack_b)->data < stack_b->top->next->data && !check_desc(stack_b))
			{
				rrb(stack_b);
				x++;
			}
			if (stack_b->top->data < stack_b->top->next->data)
			{
				sb(stack_b);
				x++;
			}
		}
	}
	// if (x)
	// {
	// 	printstack(stack_a, 'a');
	// 	printstack(stack_b, 'b');	
	// }
	*mouvs += x;
	return (x);
}

static	void	sort_newnum_pb(t_Stack *stack_b)
{
	int	x;
	int	new_num;

	x = 0;
	new_num = stack_b->top->data;
	if (lastelem(stack_b)->data < stack_b->top->data && \
		stack_b->top->data < stack_b->top->next->data && \
		stack_b->top->data < stack_b->top->next->next->data)
		rrb(stack_b);
	if (stack_b->top->data < stack_b->top->next->data)
		sb(stack_b);
}

static	void	push_umin(t_Stack *stack_a, t_Stack *stack_b)
{
	int		mouvs;
	int		flag;
	int		len;
	int 	bb;

	bb = 1;
	mouvs = 1;
	flag = 1;
	len = -1;
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
			if (lstsize(stack_b) > 2 && !check_desc(stack_b))
			{
				if (lastelem(stack_b)->data < stack_b->top->data && \
						stack_b->top->data < stack_b->top->next->data && \
							stack_b->top->data > stack_b->top->next->next->data)
					sb(stack_b);
				else
				{
					if (lastelem(stack_b)->data > stack_b->top->data)
						rb(stack_b);
				}
				if (!check_desc(stack_b))
				{
					while (!check_desc(stack_b))
						sort_newnum_pb(stack_b);
				}
				printstack(stack_a, 'a');
				printstack(stack_b, 'b');
				printf("Out of midstackB\n");
			}
		}
		if (check_asc(stack_a) && lstsize(stack_b) && check_desc(stack_b))
			pa(stack_a, stack_b);
		if (check_asc(stack_a) && !lstsize(stack_b))
			flag = 0;
		// printstack(stack_a, 'a');
		// printstack(stack_b, 'b');
	}
	//printstack(stack_a, 'a');
	//printstack(stack_b, 'b');
	// printf("\nMouvs for UMIN: %d\n", --mouvs);
}

void	chainfilter(t_Stack *stack_a, t_Stack *stack_b)
{
	push_umin(stack_a, stack_b);
	// printstack(stack_a, 'a');
	// printstack(stack_b, 'b');
}


