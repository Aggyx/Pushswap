/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:35:11 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/01 11:56:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

// static void	remove_duplicate_node(t_Stack *stack, t_Node *prev, t_Node *node)
// {
// 	printf("\t%d is a duplicate.\n", node->data);
// 	if (prev != NULL)
// 	{
// 		prev->next = node->next;
// 		free(node);
// 	}
// 	else
// 	{
// 		stack->top = node->next;
// 		free(node);
// 	}
// }

static int	check_dupli(t_Stack *stack, int	*table)
{
	t_Node	*node;
	t_Node	*prev;
	t_Node	*nxttmp;
	int		index;
	int		minnum;

	(void)prev;
	node = stack->top;
	prev = NULL;
	minnum = minlistint(stack);
	node = stack->top;
	while (node != NULL)
	{
		index = node->data - minnum;
		nxttmp = node->next;
		if (table[index] == 1)
		{
			free(table);
			return (0);
		}
		else
		{
			table[index] = 1;
			prev = node;
		}
		node = nxttmp;
	}
	free(table);
	return (1);
}

int	check_dupli_manage(t_Stack *stack)
{
	int	*table;

	//ft_printf("check_dupli\n\tmalloquing of %d\n", rangelistint(stack) - 1);
	table = (int *) ft_calloc(rangelistint(stack) - 1, sizeof(int));
	if (table == NULL)
	{	
		free(table);
		return (0);
	}
	return (check_dupli(stack, table));
}
