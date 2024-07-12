/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:45:42 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/12 23:46:53 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate_a(t_lst **head_a)
{
	int			index_min;
	const int	size_lst = ft_lst_size(*head_a);

	ft_lst_get_min(*head_a, &index_min);
	if (index_min == 0)
		return ;
	if (index_min < (size_lst / 2))
		ft_ra(head_a, 1);
	else
		ft_rra(head_a, 1);
	return (final_rotate_a(head_a));
}

int	get_cost(t_lst **head_a, t_lst **head_b, int n, int *strat)
{
	const int	pos_target = get_position(*head_a, get_target(head_a, n));
	const int	pos_n = get_position(*head_b, n);
	const int	size_a = ft_lst_size(*head_a);
	const int	size_b = ft_lst_size(*head_b);
	int			tab[4];

	tab[0] = pos_n;
	tab[1] = size_b - pos_n;
	if (pos_n == 0)
		tab[1] = 0;
	tab[2] = pos_target;
	tab[3] = size_a - pos_target;
	if (pos_target == 0)
		tab[3] = 0;
	return (get_min_score(tab, strat));
}

void	get_cheapest_cost_n(t_lst **head_a, t_lst **head_b, t_score *score)
{
	t_lst	*ptr;
	int		cost;
	int		final_n;
	int		curr_cost;
	int		final_strat;

	cost = get_cost(head_a, head_b, (*head_b)->n, &(score->strat));
	final_strat = score->strat;
	final_n = (*head_b)->n;
	ptr = *head_b;
	while (ptr != NULL)
	{
		curr_cost = get_cost(head_a, head_b, ptr->n, &(score->strat));
		if (curr_cost < cost)
		{
			final_n = ptr->n;
			cost = curr_cost;
			final_strat = score->strat;
		}
		ptr = ptr->next;
	}
	score->n = final_n;
	score->cost = cost;
	score->target = get_target(head_a, final_n);
	score->strat = final_strat;
}

void	make_empty_b(t_lst **head_a, t_lst **head_b)
{
	t_score	score;

	if (*head_b == NULL)
		return ;
	get_cheapest_cost_n(head_a, head_b, &score);
	apply_strat(head_a, head_b, score);
	return (make_empty_b(head_a, head_b));
}

void	ft_big_sort(t_lst **head_a, t_lst **head_b)
{
	ft_init_second_stack(head_a, head_b);
	ft_sort_by_3(head_a);
	make_empty_b(head_a, head_b);
	final_rotate_a(head_a);
}
