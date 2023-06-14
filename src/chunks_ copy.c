/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:42:34 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/14 11:40:05 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	t_Node	*secmaxnode(t_Stack	*stack, int curr_max)
{
	t_Node	*tmp;
	int		minnumber;

	tmp = stack->top;
	minnumber = 0;
	while (tmp != NULL)
	{
		if (tmp->data > minnumber && tmp->data < curr_max)
			minnumber = tmp->data;
		tmp = tmp->next;
	}
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->data == minnumber)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

static	int	btoa_down_norm(t_Stack *a, t_Stack *b, t_Node *nxt, int index)
{
	int	index_sec;
	int	swp;
	int	len;

	len = lstsize(b);
	swp = 0;
	index_sec = get_stack_index(b, nxt);
	if (index_sec > index)
	{
		swp = 1;
		while ((len - index_sec))
		{
			rrb(b);
			index_sec++;
		}
		pa(a, a);
	}
	while ((len - index))
	{
		rrb(b);
		index++;
	}
	pa(a, b);
	return (swp);
}

static	int	btoa_up_norm(t_Stack *a, t_Stack *b, t_Node *nxt, int index)
{
	int	index_sec;
	int	swp;

	swp = 0;
	index_sec = get_stack_index(b, nxt);
	if (index_sec < index)
	{	
		swp = 1;
		while (index_sec)
		{
			rb(b);
			index_sec--;
		}
		pa(a, a);
	}
	while (index)
	{
		rb(b);
		index--;
	}
	pa(a, b);
	return (swp);
}

static	void	btoa(t_Stack *a, t_Stack *b, t_Node *node, t_Node *nxt)
{
	int		len;
	int		index;
	int		swp;

	swp = 0;
	len = lstsize(b);
	index = get_stack_index(b, node);
	if (index < (len / 2))
		swp = btoa_up_norm(a, b, nxt, index);
	else
		swp = btoa_down_norm(a, b, nxt, index);
	if (swp)
		sa(a);
}

void	push_chunks_to_a(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*node;
	t_Node	*node_nxt;

	while (lstsize(stack_b) != 0)
	{	
		node = maxlistnode(stack_b);
		node_nxt = secmaxnode(stack_b, node->data);
		btoa(stack_a, stack_b, node, node_nxt);
	}
}
