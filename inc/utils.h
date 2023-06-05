/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:17:25 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/05 15:03:07 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft/libft.h"

typedef struct Node
{
	int				data;
	struct Node		*next;
}		t_Node;

typedef struct Stack
{
	struct Node	*top;
}		t_Stack;

//instructions
void	sa(t_Stack *stac_a);
void	sb(t_Stack *stack_b);
void	ra(t_Stack *stack_a);
void	rb(t_Stack *stack_b);
void	rra(t_Stack *stack_a);
void	rrb(t_Stack *stack_b);
void	pb(t_Stack *stack_a, t_Stack *stack_b);
void	pa(t_Stack *stack_a, t_Stack *stack_b);
void	pb(t_Stack *stack_a, t_Stack *stack_b);
void	pa(t_Stack *stack_a, t_Stack *stack_b);
//Linked List funcs
t_Node	*lastelem(t_Stack	*stack);
void	printstack(t_Stack *stack, char id);
int		minlistint(t_Stack	*stack);
int		maxlistint(t_Stack	*stack);
int		rangelistint(t_Stack	*stack);
int		lstsize(t_Stack *lst);
void	initialize(t_Stack *stack);
int		is_empty(t_Stack *stack);
void	freestack(t_Stack	*stack);
void	push(t_Stack *stack, int x);
int		pop(t_Stack *stack);
int		peek(t_Stack *stack);
//Parse Params
void	parse_params(t_Stack *stack, char **entry);
int		check_asc(t_Stack *stack);
int		check_desc(t_Stack *stack);
int		check_dupli_manage(t_Stack *stack);
//algo
void	quickSortLinkedList(t_Node **head, t_Node **tail);
void	panic(t_Stack	*stack, int error);
void	panic(t_Stack	*stack, int error);

void	chainfilter(t_Stack *stack_a, t_Stack *stack_b);
#endif