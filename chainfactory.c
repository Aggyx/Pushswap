/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainfactory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:19:04 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/05 17:18:49 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	int	filter(t_Stack *stack_a, t_Stack *stack_b, int *mouvs)
{
	int	x;

	x = 0;
	if (stack_a->top->data > stack_a->top->next->data)
	{
		if (stack_a->top->data > stack_a->top->next->data && \
			stack_a->top->data > lastelem(stack_a)->data)
			ra(stack_a);
		else
			sa(stack_a);
		// printstack(stack_a, 'a');
		// printstack(stack_b, 'b');
		x++;
	}
	if (lastelem(stack_a)->data < stack_a->top->data)
	{
		rra(stack_a);
		// printstack(stack_a, 'a');
		// printstack(stack_b, 'b');
		x++;
	}
	if (lastelem(stack_a)->data < stack_a->top->next->data && \
		lastelem(stack_a)->data > stack_a->top->data)
	{
		rra(stack_a);
		x++;
		sa(stack_a);
		// printstack(stack_a, 'a');
		// printstack(stack_b, 'b');
		x++;
	}
	if (lstsize(stack_b) > 1)
	{
		if (lastelem(stack_b)->data > stack_b->top->data)
		{
			rb(stack_b);
			// printstack(stack_a, 'a');
			// printstack(stack_b, 'b');
			// printstack(stack_b, 'b');
			x++;
		}
		if (stack_b->top->data < stack_b->top->next->data)
		{
			sb(stack_b);
			// printstack(stack_a, 'a');
			// printstack(stack_b, 'b');
			// printstack(stack_b, 'b');
			x++;
		}
		// else
		// {
		// 	/*
		// 	tengo un numero en nodo->data que se tiene que poner en su index en stack_b
		// 	sabiendo que a priori stack_b esta ordenada
		// 	Y no es m'as pequeno que lastelement y tmp del primero. entonces RRA y SA unicanmente no sirve.
		// 	Puede estar en medio.
		// 	*/
		// }
	}
	*mouvs += x;
	return (x);
}

static	void	push_umin(t_Stack *stack_a, t_Stack *stack_b)
{
	int		mouvs;
	int		flag;
	int		len;

	(void)len;
	mouvs = 1;
	flag = 1;
	len = 0;
	if (stack_a->top->next == NULL)
		return ;
	while (flag)
	{
		while (filter(stack_a, stack_b, &mouvs))
			;
		if (!check_asc(stack_a)) //&& minlistint(stack_a) == stack_a->top->data)
		{
			pb(stack_a, stack_b);
			// printstack(stack_a, 'a');
			// printstack(stack_b, 'b');
			mouvs++;
		}
		// else if (!check_asc(stack_a) && \
		// 	minlistint(stack_a) != stack_a->top->data)
		// 	rra(stack_a);
		if (check_asc(stack_a) && lstsize(stack_b) && check_desc(stack_b))
			pa(stack_a, stack_b);
			// len = lstsize(stack_b) + 1;
			// while (len)
			// {	
			// 	pa(stack_a, stack_b);
			// 	mouvs++;
			// 	len--;
			// }
			// printstack(stack_a, 'a');
			// printstack(stack_b, 'b');
			// flag = 0;
		if (check_asc(stack_a) && !lstsize(stack_b))
			flag = 0;
		printstack(stack_a, 'a');
		printstack(stack_b, 'b');
	}
	//printstack(stack_a, 'a');
	//printstack(stack_b, 'b');
	// printf("\nMouvs for UMIN: %d\n", --mouvs);
}

// static	void	arrange_max(t_Stack	*stack_a)
// {
// 	int		flagmin;
// 	int		mouvs;

// 	printf("\nArranging max numbers in stack_a:\n");
// 	mouvs = 0;
// 	flagmin = 1;
// 	while (flagmin)
// 	{
// 		printstack(stack_a, 'a');
// 		if (stack_a->top->data > stack_a->top->next->data)
// 		{
// 			swap(stack_a);
// 			mouvs++;
// 		}
// 		else if (lastelem(stack_a)->data < stack_a->top->data)
// 		{	
// 			rotate(stack_a);
// 			mouvs++;
// 		}
// 		else
// 		{	
// 			if (minlistint(stack_a) == stack_a->top->data)
// 				flagmin = 0;
// 			reverse_rotate(stack_a);
// 			mouvs++;
// 		}
// 		printf("\n---------------\n");
// 	}
// 	printf("\nAccumulative Mouvs for arrange max: %d\n", mouvs);
// }

void	chainfilter(t_Stack *stack_a, t_Stack *stack_b)
{
	push_umin(stack_a, stack_b);
	// printstack(stack_a, 'a');
	// printstack(stack_b, 'b');
}


