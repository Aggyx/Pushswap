/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc___.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:17:56 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/17 14:18:29 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

t_Node	*lastelem(t_Stack	*stack)
{
	t_Node	*tmp;

	tmp = stack->top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

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
	int	chunk;

	chunk = 1;
	if (ttlen == 100)
		chunk = 5;
	else if (ttlen == 500)
		chunk = 10;
	else if (ttlen < 50)
		chunk = 3 + (ttlen - 6) / 7;
	else if (ttlen >= 50 && ttlen < 100)
		chunk = 5 + (ttlen - 50) / 8;
	else if (ttlen > 100 && ttlen < 350)
		chunk = 10;
	else if (ttlen >= 350 && ttlen < 500)
		chunk = 10 + (ttlen - 350) / 15;
	else if (ttlen > 500)
		chunk = 20 + (ttlen - 500) / 20;
	return (chunk);
}
