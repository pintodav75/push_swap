/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 02:16:05 by dpinto            #+#    #+#             */
/*   Updated: 2024/06/30 01:38:59 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intervertit les 2 premiers éléments au sommet de la pile a
void	ft_sa(t_lst **head, int display)
{
	if (display)
		ft_putendl_fd("sa", 1);
	if (*head == NULL)
		return ;
	if ((*head)->next == NULL)
		return ;
	ft_swap(&((*head)->n), &((*head)->next->n));
}

// Intervertit les 2 premiers éléments au sommet de la pile b
void	ft_sb(t_lst **head, int display)
{
	if (display)
		ft_putendl_fd("sb", 1);
	if (*head == NULL)
		return ;
	if ((*head)->next == NULL)
		return ;
	ft_swap(&((*head)->n), &((*head)->next->n));
}

// Intervertit les 2 premiers éléments au sommet de la pile a et de la pile b.
void	ft_ss(t_lst **head_a, t_lst **head_b)
{
	ft_putendl_fd("ss", 1);
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
}

// Prend le premier élément au sommet de b et le met sur a.
void	ft_pa(t_lst **head_a, t_lst **head_b)
{
	ft_putendl_fd("pa", 1);
	ft_p(head_b, head_a);
}

// Prend le premier élément au sommet de a et le met sur b.
void	ft_pb(t_lst **head_b, t_lst **head_a)
{
	ft_putendl_fd("pb", 1);
	ft_p(head_a, head_b);
}
