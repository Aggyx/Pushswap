/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:42:34 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/13 18:02:43 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	node_to_top_b(t_Stack *stack, t_Node *node)
{
	int		len;
	int		index;

	len = lstsize(stack);
	index = get_stack_index(stack, node);
	if (index < (len / 2))
	{
		while (index)
		{
			rb(stack);
			index--;
		}
	}
	else
	{
		while ((len - index))
		{
			rrb(stack);
			index++;
		}
	}
}

void	push_chunks_to_a(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Node	*node;

	while (lstsize(stack_b) != 0)
	{	
		node = maxlistnode(stack_b);
		node_to_top_b(stack_b, node);
		pa(stack_a, stack_b);
	}
}
