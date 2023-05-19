/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/19 16:39:55 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

int	main(int argc, char *argv[])
{
	t_Stack	stack_a;
	t_Stack	stack_b;
	t_Node	*curr_node;
	int		i;
	int		x;

	initialize(&stack_a);
	initialize(&stack_b);
	i = 0;
	x =	0;
    //Read numbers from cmmdline args and push them onto stack A
	while (i < argc)
	{
		x = ft_atoi(argv[i]);
		push(&stack_a, x);
		i++;
	}
	printf("Stack A (initial state): ");
	curr_node = stack_a.top;
	while (curr_node != NULL)
	{
		printf("%d ", curr_node->data);
		curr_node = curr_node->next;
	}
	printf("\n");
	return (0);
}
