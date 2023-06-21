/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusushuape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:18:39 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/21 11:59:02 by smagniny         ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 2);
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

void	sort(t_Stack *stack_a, t_Stack *stack_b)
{
	int	ch;

	ch = num_chunks(lstsize(stack_a));
	if (lstsize(stack_a) <= 5)
		chainfilter(stack_a, stack_b);
	else
		chunks_to_b(stack_a, stack_b, lstsize(stack_a), ch);
}

/* void ft_leaks()
{
	system("leaks -q push_swap");
	atexit(ft_leaks);
} */

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	stack_a = (t_Stack *)ft_calloc(1, sizeof(t_Stack));
	stack_b = (t_Stack *)ft_calloc(1, sizeof(t_Stack));
	stack_a->top = NULL;
	stack_b->top = NULL;
	if (check_digits(argv))
		panic(1, 2, stack_a, stack_b);
	if (argc >= 2)
		parse_params(stack_a, argv, stack_b);
	else
		panic(0, 2, stack_a, stack_b);
	if (check_dupli(stack_a) == 0)
		panic(1, 2, stack_a, stack_b);
	else if (check_asc(stack_a) == 1)
		panic(0, 2, stack_a, stack_b);
	else
	{
		set_index(stack_a);
		sort(stack_a, stack_b);
		freestack(stack_a);
		freestack(stack_b);
	}
	return (0);
}
