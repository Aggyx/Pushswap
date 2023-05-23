/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:22:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/23 17:32:39 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

int	lstsize(t_Stack *lst)
{
	size_t	i;
	t_Node	*ptr;

	i = 0;
	ptr = lst->top;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
