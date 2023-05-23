/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:40:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/23 17:46:24 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	void	parse_params_norm(t_Stack *stack, char **entry, int index)
{
	char	**tmp;
	int		i;

	(void)stack;
	tmp = ft_split(entry[index], ' ');
	i = ft_lendb(tmp) - 1;
	if (tmp == NULL || i == 0)
		return ;
	while (tmp[i] != NULL || tmp[i] != '\0')
		push(stack, ft_atoi(tmp[i--]));
}

void	parse_params(t_Stack *stack, char **entry)
{
	int	i;
	int	j;
	int	l;

	(void)stack;
	i = 0;
	j = 0;
	l = ft_lendb(entry) - 1;
	printf("Number of param: %d\n", l);
	while (l >= 1)
	{
		if (ft_lendb(ft_split(entry[l], ' ')) > 1)
			parse_params_norm(stack, entry, l);
		else
			push(stack, ft_atoi(entry[l]));
		l--;
	}
}

int	check_order(t_Stack *stack)
{
	t_Node	*node;

	node = stack->top;
	while (node->next != NULL)
	{
		if (node->data < node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

static	int	check_dupli_tmp(int *tmp, int num)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i++] == num)
			return (1);
	}
	return (0);
}

int	check_dupli(t_Stack *stack)
{
	t_Node	*node;
	int		*tmp;
	int		i;


	(void)node;
	(void)tmp;
	i = 0;
	tmp = (int *)ft_calloc(lstsize(stack), sizeof(int));
	if (!tmp)
		return (0);
	node = stack->top;
	while (node->next != NULL)
	{
		if (check_dupli_tmp(tmp, node->data) == 0)
			tmp[i++] = node->data;
		else
			printf("%d esta duplicado.\n", node->data);
		node = node->next;
	}
	int	j;

	j = -1;
	while (++j <= i)
		printf("list[%d]: %d\n", j, tmp[j]);
	free(tmp);
	return (1);
}
