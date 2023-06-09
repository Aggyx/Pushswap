/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:25:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/06/09 17:39:46 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

int set_index(t_Stack *stack)
{
    int     x;
    t_Stack *tmp;
    t_Node  *Ntmp;
    int     extra;

    tmp = stack;
    Ntmp = tmp->top;
    x = 0;
    extra = 0;
    while (Ntmp)
    {
        if (tmp->top->next->data < tmp->top->data)
        {
            extra = tmp->top->data;
            tmp->top->data = tmp->top->next->data;
            tmp->top->next->data = extra;
        }
        Ntmp = Ntmp->next;
    }
    while (Ntmp)
    {
        Ntmp->index = x;
        x++;
        Ntmp = Ntmp->next;
    }
}