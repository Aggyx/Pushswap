/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:17:25 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/12 18:53:58 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft/libft.h"

typedef struct Node
{
	int				data;
	int				index;
	struct Node		*prev;
	struct Node		*next;
}		t_Node;

typedef struct Stack
{
	struct Node	*top;
}		t_Stack;

//developpement
void	printstack(t_Stack *stack, char id);
//QUIT
void	panic(int error, int num_args, ...);
//instructions
void	sa(t_Stack *stac_a);
void	sb(t_Stack *stack_b);
void	ra(t_Stack *stack_a);
void	rb(t_Stack *stack_b);
void	rra(t_Stack *stack_a);
void	rrb(t_Stack *stack_b);
void	pb(t_Stack *stack_a, t_Stack *stack_b);
void	pa(t_Stack *stack_a, t_Stack *stack_b);
//Lists funcs
int		is_empty(t_Stack *stack);
t_Node	*lastelem(t_Stack	*stack);
void	push(t_Stack *stack, int x);
int		pop(t_Stack *stack);
void	reverse_rotate(t_Stack *stack);
int		check_asc(t_Stack *stack);
int		check_desc(t_Stack *stack);
void	freestack(t_Stack	*stack);
t_Node	*minlistnode(t_Stack	*stack);
int		lstsize(t_Stack *lst);
t_Stack	*cpystack(t_Stack	*stack);
int		get_stack_index(t_Stack *stack, t_Node *node);
//parse input
void	parse_params(t_Stack *stack, char **entry);
//Check 4 duplicates
int		check_dupli_manage(t_Stack *stack);
int		rangelistint(t_Stack	*stack);
//take index
void	set_index(t_Stack *tstack);
//sorting algo
void	radix_sort(t_Stack *stack_a, t_Stack *stack_b);

int		filter_b(t_Stack *b);
void	find_to_push(t_Stack *stack_a, t_Stack *stack_b);
void	node_to_top(t_Stack *stack, t_Node *node);
void	chainfilter(t_Stack *stack_a, t_Stack *stack_b);
#endif