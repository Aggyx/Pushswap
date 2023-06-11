/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpystack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:34:34 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 18:11:24 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	enter_info_node(t_Node *newnode, t_Node *current)
{
	newnode->data = current->data;
	newnode->index = current->index;
	newnode->next = NULL;
}

static	t_Node	*newnode__norm(t_Stack *s)
{
	t_Node	*node;

	node = (t_Node *)malloc(sizeof(t_Node));
	if (node == NULL)
	{
		free(s);
		return (NULL);
	}
	return (node);
}

t_Stack	*cpystack(t_Stack	*stack)
{
	t_Stack	*newstack;
	t_Node	*current;
	t_Node	*prev;
	t_Node	*newnode;
	t_Node	*newtop;

	prev = NULL;
	newnode = NULL;
	newtop = NULL;
	newstack = (t_Stack *)ft_calloc(1, sizeof(t_Stack));
	newstack->top = NULL;
	current = stack->top;
	while (current != NULL)
	{
		newnode = newnode__norm(newstack);
		enter_info_node(newnode, current);
		if (prev != NULL)
			prev->next = newnode;
		else
			newtop = newnode;
		prev = newnode;
		current = current->next;
	}
	newstack->top = newtop;
	return (newstack);
}
