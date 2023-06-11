/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:52:32 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/11 15:59:09 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	get_max_bits(t_Stack *stack)
{
	t_Stack	*head;
	t_Node	*node;
	int		max;
	int		max_bits;

	head = stack;
	node = head->top;
	max = node->index;
	max_bits = 0;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_Stack *stack_a, t_Stack *stack_b)
{
	t_Stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack_a;
	size = lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack_a;
			if (((head_a->top->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (lstsize(stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
