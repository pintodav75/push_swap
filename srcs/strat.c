/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:36:21 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/07 19:39:41 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_a(t_lst **head_a, t_lst **head_b, t_score score)
{
	const int	index_target = get_position(*head_a, score.target);
	const int	index_n = get_position(*head_b, score.n);

	if (index_target == 0 && index_n == 0)
	{
		ft_pa(head_a, head_b);
		return ;
	}
	if (index_n && index_target)
	{
		ft_rr(head_a, head_b);
		return (apply_a(head_a, head_b, score));
	}
	if (index_target)
		ft_ra(head_a, 1);
	if (index_n)
		ft_rb(head_b, 1);
	return (apply_a(head_a, head_b, score));
}

void	apply_b(t_lst **head_a, t_lst **head_b, t_score score)
{
	const int	index_target = get_position(*head_a, score.target);
	const int	index_n = get_position(*head_b, score.n);

	if (index_target == 0 && index_n == 0)
	{
		ft_pa(head_a, head_b);
		return ;
	}
	if (index_n && index_target)
	{
		ft_rrr(head_a, head_b);
		return (apply_b(head_a, head_b, score));
	}
	if (index_target)
		ft_rra(head_a, 1);
	if (index_n)
		ft_rrb(head_b, 1);
	return (apply_b(head_a, head_b, score));
}

void	apply_c(t_lst **head_a, t_lst **head_b, t_score score)
{
	const int	index_target = get_position(*head_a, score.target);
	const int	index_n = get_position(*head_b, score.n);

	if (index_target == 0 && index_n == 0)
	{
		ft_pa(head_a, head_b);
		return ;
	}
	if (index_target)
		ft_rra(head_a, 1);
	if (index_n)
		ft_rb(head_b, 1);
	return (apply_c(head_a, head_b, score));
}

void	apply_d(t_lst **head_a, t_lst **head_b, t_score score)
{
	const int	index_target = get_position(*head_a, score.target);
	const int	index_n = get_position(*head_b, score.n);

	if (index_target == 0 && index_n == 0)
	{
		ft_pa(head_a, head_b);
		return ;
	}
	if (index_target)
		ft_ra(head_a, 1);
	if (index_n)
		ft_rrb(head_b, 1);
	return (apply_d(head_a, head_b, score));
}

void	apply_strat(t_lst **head_a, t_lst **head_b, t_score score)
{
	if (score.strat == STRAT_A)
		apply_a(head_a, head_b, score);
	if (score.strat == STRAT_B)
		apply_b(head_a, head_b, score);
	if (score.strat == STRAT_C)
		apply_c(head_a, head_b, score);
	if (score.strat == STRAT_D)
		apply_d(head_a, head_b, score);
}
