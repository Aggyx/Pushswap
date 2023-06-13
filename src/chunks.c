/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:10:40 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/13 18:08:11 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	node_to_top_a(t_Stack *stack, t_Node *node)
{
	int		len;
	int		index;

	len = lstsize(stack);
	index = get_stack_index(stack, node);
	if (index < (len / 2))
	{
		while (index)
		{
			ra(stack);
			index--;
		}
	}
	else
	{
		while ((len - index))
		{
			rra(stack);
			index++;
		}
	}
}

static	t_Node	*read_top(t_Stack *stack, int st, int end)
{
	t_Node	*hold;
	t_Node	*tmp;

	tmp = stack->top;
	hold = NULL;
	while (tmp)
	{
		if (tmp->index >= st && tmp->index <= end)
		{
			hold = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	return (hold);
}

static	t_Node	*read_bottom(t_Stack *stack, int st, int end)
{
	t_Node	*hold;
	t_Node	*tmp;

	tmp = lastelem(stack);
	hold = NULL;
	while (tmp)
	{
		if (tmp->index >= st && tmp->index <= end)
		{
			hold = tmp;
			break ;
		}
		tmp = tmp->prev;
	}
	return (hold);
}

static	void	chunks_to_b__norm(t_Stack *stack_b, int len, int ch, int k)
{
	if (lstsize(stack_b) > 1)
	{
		if (stack_b->top->data > ((len / ch) * (k - 1)) && \
			stack_b->top->data < (((len / ch) * k) - (len / ch) / 2))
			rb(stack_b);
	}
}

void	chunks_to_b(t_Stack *stack_a, t_Stack *stack_b, int len, int ch)
{
	t_Node	*hold_first;
	t_Node	*hold_sec;
	int		i;
	int		st;
	int		k;

	k = 0;
	st = 0;
	while (++k <= ch)
	{
		i = -1;
		while (++i < (len / ch))
		{
			hold_first = read_top(stack_a, st, ((len / ch) * k) - 1);
			hold_sec = read_bottom(stack_a, st, ((len / ch) * k) - 1);
			if (intotop(stack_a, hold_first) <= intotop(stack_a, hold_sec))
				node_to_top_a(stack_a, hold_first);
			else
				node_to_top_a(stack_a, hold_sec);
			pb(stack_a, stack_b);
			chunks_to_b__norm(stack_b, len, ch, k);
		}
		st += (len / ch);
	}
	push_chunks_to_a(stack_a, stack_b);
}



