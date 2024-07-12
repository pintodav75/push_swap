/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 01:41:59 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/13 01:01:12 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*get_inital_lst(char **av)
{
	t_lst	*head;
	t_lst	*node;
	int		i;

	head = NULL;
	i = 0;
	while (av[i] != NULL)
	{
		node = ft_lst_create_node(ft_atoi(av[i]));
		if (node == NULL)
			return (NULL);
		ft_lst_push_back(&head, node);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	char	**tab;

	if (ac == 1)
		return (0);
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
		tab = dup_map(av + 1);
	if (parse(tab))
	{
		free_strs(tab);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	lst_b = NULL;
	lst_a = get_inital_lst(tab);
	if (lst_a == NULL)
		ft_putstr_fd("Error\n", 2);
	else
		compute(&lst_a, &lst_b);
	free_lst(lst_a);
	free_strs(tab);
	return (0);
}
