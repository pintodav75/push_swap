/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 02:05:08 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/07 19:58:38 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_second_stack(t_lst **head_a, t_lst **head_b)
{
	const int	lst_size = ft_lst_size(*head_a);
	int			i;

	i = 0;
	while (i < lst_size - 3)
	{
		ft_pb(head_b, head_a);
		i++;
	}
}

int	compute(t_lst **head_a, t_lst **head_b)
{
	const int	lst_size = ft_lst_size(*head_a);

	if (ft_lst_is_sort(*head_a))
		return (0);
	if (lst_size == 2)
		ft_sa(head_a, 1);
	if (lst_size == 3)
		ft_sort_by_3(head_a);
	else if (lst_size == 4)
		ft_sort_by_4(head_a, head_b);
	else if (lst_size == 5)
		ft_sort_by_5(head_a, head_b);
	else if (lst_size > 5)
		ft_big_sort(head_a, head_b);
	return (0);
}
