/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:40:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/02 12:55:34 by smagniny         ###   ########.fr       */
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
		printf("atoi: %d", ft_atoi(tmp[len]));
		printf("\t\t\t Pushing %d to stack from container\n", ft_atoi(tmp[len]));
		if (ft_atoi(tmp[len--]) != False)
			push(stack, ft_atoi(tmp[len--]));
		else
			panic(stack, 1);
	}
}

void	parse_params(t_Stack *stack, char **entry)
{
	int		l;
	char	**tmp;

	l = ft_lendb(entry) - 1;
	while (l >= 1)
	{
		tmp = ft_split(entry[l], ' ');
		if (ft_lendb(tmp) > 1)
		{
			parse_params_norm(stack, tmp, l);
		}
		else
		{
			printf("atoi: %d", ft_atoi(entry[l]));
			if (ft_atoi(entry[l]) != False)
				push(stack, ft_atoi(entry[l]));
			else
				printf("Not atoi\n");
		}
		doublefree(tmp);
		l--;
	}
}

int	check_order(t_Stack *stack)
{
	t_Node	*node;

	node = stack->top;
	while (node->next != NULL && node)
	{
		if (node->data < node->next->data)
			node = node->next;
		else
		{
			//printf("Not ordered\n");
			return (0);
		}
	}
	//printf("Ordered\n");
	return (1);
}

