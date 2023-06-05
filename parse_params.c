/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:40:42 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/04 14:46:04 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

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
	if (nb != 0)
		aatoi_norm(&nb, &sign, success);
	if (success == 0)
		return (0);
	else
		return ((sign * nb));
}

static	void	parse_params_norm(t_Stack *stack, char **tmp, int index)
{
	int		len;
	int		s;

	s = 0;
	printf("\t\tContainer of number found in params in argv[%d];\n", index);
	len = ft_lendb(tmp) - 1;
	printf("\t\tlen container from zero; %d\n", len);
	if (tmp == NULL || len == 0)
		return ;
	while (len > -1)
	{
		printf("atoi: %d", aatoi(tmp[len], &s));
		printf("\t\t\t Pushing %d to stack from container\n", aatoi(tmp[len], &s));
		aatoi(tmp[len--], &s);
		if (s != False)
			push(stack, aatoi(tmp[len--], &s));
		else
			panic(stack, 1);
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
		{
			parse_params_norm(stack, tmp, l);
		}
		else
		{
			aatoi(entry[l], &s);
			if (s == 1)
				push(stack, aatoi(entry[l], &s));
			else
			{
				printf("%d\n", s);
				doublefree(tmp);
				panic(stack, 1);
			}
		}
		doublefree(tmp);
		l--;
	}
	// printstack(stack, 'a');
}

int	check_asc(t_Stack *stack)
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

int	check_desc(t_Stack *stack)
{
	t_Node	*node;

	node = stack->top;
	while (node->next != NULL && node)
	{
		if (node->data > node->next->data)
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
