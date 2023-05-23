/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/23 17:30:55 by smagniny         ###   ########.fr       */
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

	(void)argc;
	initialize(&stack_a);
	initialize(&stack_b);
	i = 0;
	x = 0;
	parse_params(&stack_a, argv);
	if (check_order(&stack_a) == 1)
		return (0);
	if (check_dupli(&stack_a) == 1)
		return (0);
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
