/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:12:55 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/21 12:51:41 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	aatoi(const char *str, int *success)
{
	long long int		nb;
	int					sign;

	sign = 1;
	nb = 0;
	if (ft_strlen(str) > 11)
		*success = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str == '\0' || str == NULL || (*str == '+' || *str == '-'))
		success = 0;
	while (success && *str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if ((nb > 2147483647 && sign == 1) || (nb > 2147483648 && sign == -1))
		*success = 0;
	return ((int)nb * sign);
}

static	void	parse_params_norm(t_Stack *stack, char **tmp)
{
	int		len;
	int		s;

	s = 1;
	len = ft_lendb(tmp) - 1;
	if (tmp == NULL || len == 0)
		return ;
	while (len > -1)
	{
		aatoi(tmp[len], &s);
		if (s == 1)
			push(stack, aatoi(tmp[len], &s));
		else
			panic(1, 1, stack);
		len--;
	}
}

static	int	__normfree(t_Stack *stack, t_Stack *stack_b, char **tmp, int i)
{	
	int	j;

	j = 0;
	if (ft_lendb(tmp) == 0 || i)
	{
		doublefree(tmp);
		panic(1, 2, stack, stack_b);
		return (0);
	}
	else
	{
		while (ft_isspace(tmp[0][j]))
			j++;
		if (tmp[0][j] == '+' || tmp[0][j] == '-')
			j++;
		if (tmp[0][j] == '+' || tmp[0][j] == '-')
			__normfree(stack, stack_b, tmp, 1);
		if (ft_strncmp(tmp[0], "9999999999", 10) == 0)
			__normfree(stack, stack_b, tmp, 1);
		else
			return (1);
	}
	return (0);
}

void	parse_params(t_Stack *stack, char **entry, t_Stack *stack_b)
{
	int		l;
	char	**tmp;
	int		s;

	s = 1;
	l = ft_lendb(entry);
	while (--l >= 1)
	{
		tmp = ft_split(entry[l], ' ');
		if (ft_lendb(tmp) > 1)
			parse_params_norm(stack, tmp);
		else
		{
			if (__normfree(stack, stack_b, tmp, 0))
			{	
				aatoi(entry[l], &s);
				if (s == 1)
					push(stack, aatoi(entry[l], &s));
				else
					__normfree(stack, stack_b, tmp, 1);
			}
		}
		doublefree(tmp);
	}
}
