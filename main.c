/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/25 16:53:27 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

// static void	sys_leaks(void)
// {
// 	system("valgrind --leak-check=full ./Push_swap");
// }

void	panic(t_Stack	*stack)
{
	freestack(stack);
	exit(0);
}

void	printstack(t_Stack *stack)
{
	t_Node	*curr_node;

	curr_node = stack->top;
	printf("Stack_a: \n");
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
	t_Node	*tail;

	(void)argc;
	// atexit(sys_leaks);
	initialize(&stack_a);
	initialize(&stack_b);
	printf("----init----\n");
	parse_params(&stack_a, argv);
	if (check_order(&stack_a) == 1)
		panic(&stack_a);
	check_dupli_manage(&stack_a);
	tail = stack_a.top;
	while (tail->next != NULL)
		tail = tail->next;
	quickSortLinkedList(&stack_a.top, &tail);
	printf("Stack A (initial state): \n");
	printstack(&stack_a);
	freestack(&stack_a);
	return (1);
}
