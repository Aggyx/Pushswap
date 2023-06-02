/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:22:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/01 02:03:34 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

int	lstsize(t_Stack *lst)
{
	size_t	i;
	t_Node	*ptr;

	if (lst->top == NULL)
		return (0);
	i = 0;
	ptr = lst->top;
	while (ptr->next != NULL && ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
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

int	minlistint(t_Stack	*stack)
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
	free(tmp);
	return (minnumber);
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
	stack->top = NULL;
}

t_Node	*lastelem(t_Stack	*stack)
{
	t_Node	*tmp;

	tmp = stack->top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
