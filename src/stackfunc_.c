/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:35:12 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/14 10:58:18 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	lstsize(t_Stack *lst)
{
	size_t	i;
	t_Node	*ptr;

	if (lst->top == NULL)
		return (0);
	i = 0;
	ptr = lst->top;
	if (ptr)
		i += 1;
	while (ptr->next != NULL && ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	freestack(t_Stack	*stack)
{
	t_Node	*node;
	t_Node	*temp;

	node = stack->top;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(stack);
}

t_Node	*minlistnode(t_Stack	*stack)
{
	t_Node	*tmp;
	int		minnumber;

	tmp = stack->top;
	minnumber = __INT_MAX__;
	while (tmp != NULL)
	{
		if (tmp->data < minnumber)
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

int	rangelistint(t_Stack	*stack)
{
	int		range;
	int		minnumber;
	int		maxnumber;
	t_Node	*node;

	node = stack->top;
	range = 0;
	minnumber = INT_MAX;
	maxnumber = INT_MIN;
	while (node != NULL)
	{
		if (node->data < minnumber)
			minnumber = node->data;
		if (node->data > maxnumber)
			maxnumber = node->data;
		node = node->next;
	}
	range = maxnumber - minnumber + 2;
	return (range);
}

int	check_desc(t_Stack *stack)
{
	t_Node	*node;

	node = stack->top;
	while (node->next != NULL && node)
	{
		if (node->data > node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
