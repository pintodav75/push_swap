/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <dpinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 03:40:13 by dpinto            #+#    #+#             */
/*   Updated: 2024/07/09 00:05:03 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_doublon(char *str, char **av, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strcmp(str, av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_max_int(char *str)
{
	long int	i;
	long int	res;

	i = 0;
	res = 0;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (0);
	if (*str == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (*str == '0' && str[1] == '\0')
		return (1);
	if (*str == '-')
		i++;
	if (str[i] == '\0' || str[i] == '0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (!ft_str_isdigit(av[i]))
			return (1);
		if (check_doublon(av[i], av, i))
			return (1);
		if (check_max_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}
