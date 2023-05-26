/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:40:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/24 18:51:31 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	void	parse_params_norm(t_Stack *stack, char **tmp, int index)
{
	int		len;

	printf("\t\tContainer of number found in params in argv[%d];\n", index);
	len = ft_lendb(tmp) - 1;
	printf("\t\tlen container from zero; %d\n", len);
	if (tmp == NULL || len == 0)
		return ;
	while (len > -1)
	{
		printf("\t\t\t Pushing %d to stack\n", ft_atoi(tmp[len]));
		push(stack, ft_atoi(tmp[len--]));
	}
}

void	parse_params(t_Stack *stack, char **entry)
{
	int		l;
	char	**tmp;

	l = ft_lendb(entry) - 1;
	printf("\tNumber of param from 1: %d\n", l);
	while (l >= 1)
	{
		tmp = ft_split(entry[l], ' ');
		if (ft_lendb(tmp) > 1)
		{
			parse_params_norm(stack, tmp, l);
		}
		else
			push(stack, ft_atoi(entry[l]));
		doublefree(tmp);
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
		{
			printf("Not ordered\n");
			return (0);
		}
	}
	printf("Ordered\n");
	return (1);
}

