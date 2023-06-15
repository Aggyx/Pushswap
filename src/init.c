/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:12:55 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/15 15:50:15 by smagniny         ###   ########.fr       */
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
		if (*success)
			return (*nb * *sign);
		else
			return (False);
	}
}

static int	aatoi(const char *str, int *success)
{
	unsigned int		nb;
	int					sign;

	sign = 1;
	nb = 0;
	if (str == NULL || *str == '\0')
		success = 0;
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
	return (aatoi_norm(&nb, &sign, success));
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
		if (s != 0)
			push(stack, aatoi(tmp[len], &s));
		else
			panic(1, 1, stack);
		len--;
	}
}

static	void	__normfree(t_Stack *stack, t_Stack *stack_b, char **tmp, int i)
{
	if (ft_lendb(tmp) == 0 || i)
	{
		doublefree(tmp);
		panic(1, 2, stack, stack_b);
	}
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
			__normfree(stack, stack_b, tmp, 0);
			if (ft_lendb(tmp) == 1)
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

