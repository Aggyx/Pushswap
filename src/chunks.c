/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:10:40 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/12 19:11:28 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	int	get_mouvs_to_top(t_Stack *stack, t_Node *node)
{
	int		len;
	int		index;
	int		mouvs;

	mouvs = 0;
	len = lstsize(stack);
	index = get_stack_index(stack, node);
	if (index < (len / 2))
		return (index);
	else
		return (len - index);
}

void	node_to_top(t_Stack *stack, t_Node *node)
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

void	find_to_push(t_Stack *stack_a, t_Stack *stack_b)
{	
	t_Stack	*rtmp;
	t_Node	*hold_first;
	t_Node	*hold_sec;
	int		i;

	i = -1;
	rtmp = NULL;
	while (++i <= 19)
	{	
		hold_first = read_top(stack_a, 0, 19);
		// printf("node first: %d    index: %d\n", hold_first->data, hold_first->index);
		hold_sec = read_bottom(stack_a, 0, 19);
		// printf("node sec: %d    index: %d\n", hold_sec->data, hold_sec->index);
		// printf("HF mouvs: %d\nHS mouvs: %d\n", get_mouvs_to_top(stack_a, hold_first), get_mouvs_to_top(stack_a, hold_sec));
		if (get_mouvs_to_top(stack_a, hold_first) <= get_mouvs_to_top(stack_a, hold_sec))
			node_to_top(stack_a, hold_first);
		else
			node_to_top(stack_a, hold_sec);
		pb(stack_a, stack_b);
	}
	printf("radix\n");
	radix_sort(stack_b, rtmp);
	printstack(stack_a, 'a');
	printstack(stack_b, 'b');
}
