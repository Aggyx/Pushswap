/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc___.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:17:56 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/13 18:01:46 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	get_stack_index(t_Stack *stack, t_Node *node)
{
	t_Node	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (node->data == tmp->data)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_Node	*maxlistnode(t_Stack	*stack)
{
	t_Node	*tmp;
	int		minnumber;

	tmp = stack->top;
	minnumber = 0;
	while (tmp != NULL)
	{
		if (tmp->data > minnumber)
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

int	intotop(t_Stack *stack, t_Node *node)
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

int	num_chunks(int ttlen)
{
	if (ttlen == 100)
		return (5);
	if (ttlen == 500)
		return (10);
	return (0);
}
