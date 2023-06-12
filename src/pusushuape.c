/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusushuape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/12 18:35:23 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	panic(int error, int num_args, ...)
{
	va_list		args;
	t_Stack		*stack;
	int			i;

	i = -1;
	va_start(args, num_args);
	while (++i < num_args)
	{
		stack = va_arg(args, t_Stack *);
		freestack(stack);
	}
	va_end(args);
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
		printf("data: %d   index: %d\n", curr_node->data, curr_node->index);
		curr_node = curr_node->next;
	}
	printf("-------\n");
}

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	stack_a = (t_Stack *)ft_calloc(1, sizeof(t_Stack));
	stack_b = (t_Stack *)ft_calloc(1, sizeof(t_Stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	if (argc > 2)
		parse_params(stack_a, argv);
	else
		panic(0, 2, stack_a, stack_b);
	if (check_dupli_manage(stack_a) == 0)
		panic(1, 2, stack_a, stack_b);
	else if (check_asc(stack_a) == 1)
		panic(0, 2, stack_a, stack_b);
	else
	{
		set_index(stack_a);
		find_to_push(stack_a, stack_b);
		freestack(stack_a);
		freestack(stack_b);
	}
	return (1);
}
