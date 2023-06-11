/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:12:55 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/10 19:28:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	aatoi_norm(unsigned	int	*nb, int *sign, int *success)
{
	if (*nb > 2147483647 && *sign == 1)
	{	
		*success = False;
		return (False);
	}
	else if (*nb > 2147483648 && *sign == -1)
	{	
		*success = False;
		return (False);
	}
	else
	{
		*success = True;
		return (*nb * *sign);
	}
}

static int	aatoi(const char *str, int *success)
{
	unsigned int		nb;
	int					sign;

	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (aatoi_norm(&nb, &sign, success));
}

static	void	parse_params_norm(t_Stack *stack, char **tmp, int index)
{
	int		len;
	int		s;

	s = 0;
	printf("\t\tContainer of number found in params in argv[%d];\n", index);
	len = ft_lendb(tmp) - 1;
	if (tmp == NULL || len == 0)
		return ;
	while (len > -1)
	{
		aatoi(tmp[len], &s);
		if (s != False)
			push(stack, aatoi(tmp[len], &s));
		else
			panic(1, 1, stack);
		len--;
	}
}

void	parse_params(t_Stack *stack, char **entry)
{
	int		l;
	char	**tmp;
	int		s;

	s = 0;
	l = ft_lendb(entry) - 1;
	while (l >= 1)
	{
		tmp = ft_split(entry[l], ' ');
		if (ft_lendb(tmp) > 1)
			parse_params_norm(stack, tmp, l);
		else
		{
			aatoi(entry[l], &s);
			if (s == 1)
				push(stack, aatoi(entry[l], &s));
			else
			{
				doublefree(tmp);
				panic(1, 1,stack);
			}
		}
		doublefree(tmp);
		l--;
	}
}

t_Node	*lastelem(t_Stack	*stack)
{
	t_Node	*tmp;

	tmp = stack->top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
