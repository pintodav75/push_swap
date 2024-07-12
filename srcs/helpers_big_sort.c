/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_big_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:48:54 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/13 00:02:16 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_target(t_lst **head_a, int n)
{
	long long int	diff;
	long long int	curr_diff;
	int				target;
	t_lst			*ptr;

	diff = -1;
	target = -1;
	ptr = *head_a;
	while (ptr != NULL)
	{
		if (ptr->n > n)
		{
			curr_diff = ft_abs((long long)ptr->n - (long long)n);
			if (diff == -1 || curr_diff < diff)
			{
				diff = curr_diff;
				target = ptr->n;
			}
		}
		ptr = ptr->next;
	}
	if (diff == -1)
		return (ft_lst_get_min(*head_a, &target));
	return (target);
}

int	get_position(t_lst *head, int n)
{
	if (head->n == n)
		return (0);
	return (1 + get_position(head->next, n));
}

int	get_min_score(const int *tab, int *strat)
{
	const int	a = 1 + max(tab[0], tab[2]);
	const int	b = 1 + max(tab[1], tab[3]);
	const int	c = tab[0] + 1 + tab[3];
	const int	d = tab[1] + 1 + tab[2];
	const int	min_score = min(min(a, b), min(c, d));

	if (a == min_score)
		*strat = 1;
	if (b == min_score)
		*strat = 2;
	if (c == min_score)
		*strat = 3;
	if (d == min_score)
		*strat = 4;
	return (min_score);
}
