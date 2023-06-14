/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:10:38 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/14 10:57:48 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	el_bubel_sort(t_Stack *stack)
{
	t_Node	*tnode;
	int		mouvs;
	int		tmp;

	tmp = 0;
	tnode = stack->top;
	mouvs = 1;
	while (mouvs)
	{
		mouvs = 0;
		while (tnode->next != NULL)
		{
			if (tnode->data > tnode->next->data)
			{
				tmp = tnode->data;
				tnode->data = tnode->next->data;
				tnode->next->data = tmp;
				mouvs++;
			}
			tnode = tnode->next;
		}
		tnode = stack->top;
	}
}

static	void	create_indexes(t_Stack *stack)
{
	t_Node	*node;
	int		index;

	index = 0;
	node = stack->top;
	while (node)
	{
		node->index = index;
		node = node->next;
		index++;
	}
}

static	void	cmp_indexes(t_Stack *stack_A, t_Stack *stack_TMP)
{
	t_Node	*node;
	t_Node	*nodetmp;

	node = stack_A->top;
	nodetmp = stack_TMP->top;
	while (node)
	{
		while (nodetmp)
		{
			if (node->data == nodetmp->data)
			{
				node->index = nodetmp->index;
				break ;
			}
			nodetmp = nodetmp->next;
		}
		nodetmp = stack_TMP->top;
		node = node->next;
	}
}

void	set_index(t_Stack *stack_a)
{
	t_Stack	*tstack;

	tstack = cpystack(stack_a);
	if (tstack == NULL)
		panic(1, 1, stack_a);
	el_bubel_sort(tstack);
	create_indexes(tstack);
	cmp_indexes(stack_a, tstack);
	freestack(tstack);
}
