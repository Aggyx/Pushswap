/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:17:25 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/25 16:44:35 by smagniny         ###   ########.fr       */
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
void	swap(t_Stack *stack);
void	rotate(t_Stack *stack);
void	reverse_rotate(t_Stack *stack);
void	push_a_to_b(t_Stack *stack_a, t_Stack *stack_b);
void	push_b_to_a(t_Stack *stack_a, t_Stack *stack_b);
//Linked List funcs
void	printstack(t_Stack *stack);
int		minlistint(t_Stack	*stack);
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
int		check_order(t_Stack *stack);
int		check_dupli_manage(t_Stack *stack);
//algo
void	quickSortLinkedList(t_Node** head, t_Node** tail);
void	panic(t_Stack	*stack);
#endif