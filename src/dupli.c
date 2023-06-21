/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:24:52 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/21 11:27:44 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	check_digits(char **entry)
{
	int	i;
	int	j;
	int	len;
	int	len_;

	i = 0;
	len = ft_lendb(entry);
	while (++i < len)
	{
		j = -1;
		len_ = ft_strlen(entry[i]);
		while (++j < len_)
		{
			if (!ft_isdigit(entry[i][j]) && entry[i][j] != ' ' && \
				entry[i][j] != '+' && entry[i][j] != '-')
				return (1);
			if ((entry[i][j] == '+' || entry[i][j] == '-') && \
				!ft_isdigit(entry[i][j + 1]))
				return (1);
			if (j != 0 && (entry[i][j] == '+' || entry[i][j] == '-') && \
				entry[i][j - 1] != ' ')
				return (1);
		}
	}
	return (0);
}

static	int	chkdup(t_Node *current, t_Stack *stack)
{
	t_Node	*tmp;
	int		rep;

	rep = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data == current->data)
			rep++;
		if (rep >= 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_dupli(t_Stack	*stack)
{
	t_Node	*node;

	node = stack->top;
	while (node)
	{
		if (chkdup(node, stack))
			return (0);
		node = node->next;
	}
	return (1);
}
