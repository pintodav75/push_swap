/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:55:00 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/09 00:00:51 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_lst *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

// return the smallest node and set index
int	ft_lst_get_min(t_lst *head, int *index)
{
	t_lst	*node;
	int		i;

	if (head == NULL)
		return (-1);
	i = 0;
	*index = 0;
	node = head;
	while (head != NULL)
	{
		if (node->n > head->n)
		{
			node = head;
			*index = i;
		}
		head = head->next;
		i++;
	}
	return (node->n);
}

// return the biggest node and set index
t_lst	*ft_lst_get_max(t_lst *head, int *index)
{
	t_lst	*node;
	int		i;

	if (head == NULL)
		return (NULL);
	i = 0;
	*index = 0;
	node = head;
	while (head != NULL)
	{
		if (node->n < head->n)
		{
			node = head;
			*index = i;
		}
		head = head->next;
		i++;
	}
	return (node);
}

char	**dup_map(char **map)
{
	size_t	map_len;
	char	**new_map;
	int		i;

	map_len = get_tab_len(map);
	new_map = (char **)malloc(sizeof(char *) * (map_len + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map[++i] != NULL)
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	return (new_map);
}

char	**free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
