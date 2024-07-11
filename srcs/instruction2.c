/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 02:51:15 by dpinto            #+#    #+#             */
/*   Updated: 2024/06/30 02:17:44 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Décale d’une position vers le haut tous les élements de la pile a
void	ft_ra(t_lst **head, int d)
{
	t_lst	*last;
	t_lst	*first;

	if (d)
		ft_putendl_fd("ra", 1);
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = first;
	while (last->next != NULL)
		last = last->next;
	(*head) = first->next;
	last->next = first;
	first->next = NULL;
}

// Décale d’une position vers le haut tous les élements de la pile b
void	ft_rb(t_lst **head, int d)
{
	t_lst	*last;
	t_lst	*first;

	if (d)
		ft_putendl_fd("rb", 1);
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = first;
	while (last->next != NULL)
		last = last->next;
	(*head) = first->next;
	last->next = first;
	first->next = NULL;
}

//  ra et rb en même temps
void	ft_rr(t_lst **head_a, t_lst **head_b)
{
	ft_putendl_fd("rr", 1);
	ft_ra(head_a, 0);
	ft_rb(head_b, 0);
}

// Décale d’une position vers le bas tous les élements de la pile a.
// Le dernier élément devient le premier
void	ft_rra(t_lst **head, int d)
{
	t_lst	*before_last;
	t_lst	*first;

	if (d)
		ft_putendl_fd("rra", 1);
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	before_last = first;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next->next = first;
	*head = before_last->next;
	before_last->next = NULL;
}

// Décale d’une position vers le bas tous les élements de la pile b.
// Le dernier élément devient le premier
void	ft_rrb(t_lst **head, int d)
{
	t_lst	*before_last;
	t_lst	*first;

	if (d)
		ft_putendl_fd("rrb", 1);
	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	before_last = first;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next->next = first;
	*head = before_last->next;
	before_last->next = NULL;
}
