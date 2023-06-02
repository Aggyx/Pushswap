/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainfactory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:19:04 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/01 14:14:24 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

static	void	bfilter(t_Stack *stack_b)
{
	if (lstsize(stack_b) > 1)
	{
		if (stack_b->top->data < stack_b->top->next->data)
			sa(stack_b);
		if (lastelem(stack_b)->data > stack_b->top->data)
			ra(stack_b);
	}
}


static	void	push_umin(t_Stack *stack_a, t_Stack *stack_b)
{
	int		mouvs;
	int		flagmin;
	int		len;

	mouvs = 0;
	flagmin = 1;
	len = 0;
	while (flagmin)
	{
		// printstack(stack_a, 'a');
		// printstack(stack_b, 'b');
		if (stack_a->top->data > stack_a->top->next->data)
		{
			sa(stack_a);
			mouvs++;
		}
		if (lastelem(stack_a)->data < stack_a->top->data)
		{	
			ra(stack_a);
			mouvs++;
		}
		bfilter(stack_b);
			// if (minlistint(stack_a) == stack_a->top->data)
			// {	
			// 	flagmin = 0;
			// 	printf("Empezar a ordernar stack_a\n");
			// 	flagmin = 0;
			// }

		if (check_order(stack_a))
		{
			len = lstsize(stack_b) + 1;
			while (--len > -1)
			{	
				push_b_to_a(stack_a, stack_b);
				mouvs++;
			}
			flagmin = 0;
		}
		if (flagmin)
		{
			push_a_to_b(stack_a, stack_b);
			mouvs++;
		}
	}
	//printf("\nMouvs for UMIN: %d\n", mouvs);
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


