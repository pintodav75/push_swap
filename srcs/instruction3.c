/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:38:40 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/07 20:02:06 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra et rrb en même temps
void	ft_rrr(t_lst **head_a, t_lst **head_b)
{
	ft_putendl_fd("rrr", 1);
	ft_rra(head_a, 0);
	ft_rrb(head_b, 0);
}

void	ft_p(t_lst **head_from, t_lst **head_to)
{
	t_lst	*ptr;

	if (*head_from == NULL)
		return ;
	ft_lst_push_front(head_to, ft_lst_create_node((*head_from)->n));
	ptr = *head_from;
	(*head_from) = (*head_from)->next;
	free(ptr);
}
