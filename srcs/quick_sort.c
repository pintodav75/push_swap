/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:29:27 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/05 02:30:10 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_by_3(t_lst **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->n;
	second = (*head)->next->n;
	third = (*head)->next->next->n;
	if (first < second && second < third)
		return ;
	if (first > second && second > third)
	{
		ft_sa(head, 1);
		ft_rra(head, 1);
	}
	else if (first > second && second < third && first > third)
		ft_ra(head, 1);
	else if (first > second && second < third && first < third)
		ft_sa(head, 1);
	else if (first < second && second > third && first < third)
	{
		ft_sa(head, 1);
		ft_ra(head, 1);
	}
	else if (first < second && second > third && first > third)
		ft_rra(head, 1);
}

void	ft_sort_by_4(t_lst **head_a, t_lst **head_b)
{
	int	min_index;

	ft_lst_get_min((*head_a), &min_index);
	if (min_index == 0)
	{
		ft_pb(head_b, head_a);
		ft_sort_by_3(head_a);
		ft_pa(head_a, head_b);
	}
	if (min_index == 1 || min_index == 2)
	{
		ft_ra(head_a, 1);
		if (min_index == 2)
			ft_ra(head_a, 1);
		ft_pb(head_b, head_a);
		ft_sort_by_3(head_a);
		ft_pa(head_a, head_b);
	}
	if (min_index == 3)
	{
		ft_rra(head_a, 1);
		ft_pb(head_b, head_a);
		ft_sort_by_3(head_a);
		ft_pa(head_a, head_b);
	}
}

void	ft_sort_by_5(t_lst **head_a, t_lst **head_b)
{
	int	min_index;

	ft_lst_get_min((*head_a), &min_index);
	if (min_index == 1)
		ft_ra(head_a, 1);
	else if (min_index == 2)
	{
		ft_ra(head_a, 1);
		ft_ra(head_a, 1);
	}
	else if (min_index == 3)
	{
		ft_rra(head_a, 1);
		ft_rra(head_a, 1);
	}
	else if (min_index == 4)
		ft_rra(head_a, 1);
	ft_pb(head_b, head_a);
	ft_sort_by_4(head_a, head_b);
	ft_pa(head_a, head_b);
	ft_pa(head_a, head_b);
}
