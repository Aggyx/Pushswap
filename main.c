/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/05 16:41:14 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

// static void	sys_leaks(void)
// {
// 	system("valgrind --leak-check=full ./Push_swap");
// }
void	panic(t_Stack	*stack, int error)
{
	freestack(stack);
	if (error)
		ft_putendl_fd("Error\n", 2);
	exit(0);
}

void	printstack(t_Stack *stack, char id)
{
	t_Node	*curr_node;

	curr_node = stack->top;
	printf("\nStack_%c: \n", id);
	while (curr_node != NULL)
	{
		printf("%d \n", curr_node->data);
		curr_node = curr_node->next;
	}
	printf("-------\n");
}

int	main(int argc, char *argv[])
{
	t_Stack	stack_a;
	t_Stack	stack_b;

	if (argc < 2)
		return (0);
	// atexit(sys_leaks);
	initialize(&stack_a);
	initialize(&stack_b);
	parse_params(&stack_a, argv);
	if (check_asc(&stack_a) == 1)
		panic(&stack_a, 0);
	if (check_dupli_manage(&stack_a) == 0)
		panic(&stack_a, 1);
	chainfilter(&stack_a, &stack_b);
	freestack(&stack_a);
	freestack(&stack_b);
	return (1);
}
