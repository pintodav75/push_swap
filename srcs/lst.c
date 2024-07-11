/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 01:52:43 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/07 20:01:29 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lst_create_node(int n)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

void	ft_lst_push_front(t_lst **head, t_lst *node)
{
	t_lst	*ptr;

	ptr = *head;
	*head = node;
	(*head)->next = ptr;
}

void	ft_lst_push_back(t_lst **head, t_lst *node)
{
	t_lst	*ptr;

	ptr = *head;
	if (ptr == NULL)
	{
		*head = node;
		return ;
	}
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = node;
			break ;
		}
		ptr = ptr->next;
	}
}

int	ft_lst_is_sort(t_lst *head)
{
	if (head == NULL || head->next == NULL)
		return (1);
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}
