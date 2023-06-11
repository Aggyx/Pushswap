/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:24:52 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 17:02:34 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	__norm(int *table)
{
	free(table);
	return (0);
}

static int	check_dupli(t_Stack *stack, int	*table)
{
	t_Node	*node;
	t_Node	*nxttmp;
	int		index;
	int		minnum;

	node = stack->top;
	minnum = minlistint(stack);
	node = stack->top;
	while (node != NULL)
	{
		index = node->data - minnum;
		nxttmp = node->next;
		if (table[index] == 1)
			return (__norm(table));
		else
			table[index] = 1;
		node = nxttmp;
	}
	free(table);
	return (1);
}

int	check_dupli_manage(t_Stack *stack)
{
	int	*table;

	table = (int *) ft_calloc(rangelistint(stack) - 1, sizeof(int));
	if (table == NULL)
	{	
		free(table);
		return (0);
	}
	return (check_dupli(stack, table));
}
