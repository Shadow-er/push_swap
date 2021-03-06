/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:33:36 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/24 15:52:37 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_integer(char *argv[], int argc, int i, int j)
{
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				return (0);
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			while (ft_isdigit(argv[i][j]) == 1)
				j++;
			if (argv[i][j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					return (0);
			}
		}
		i++;
	}	
	return (1);
}

int	check_duplicata(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j)
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					return (0);
			}
			j++;
		}
		i++;
	}	
	return (1);
}

int	check_scope(char *argv)
{
	unsigned long long	re;
	int					j;
	char				*p;

	j = 1;
	re = 0;
	p = (char *)argv;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			j = -j;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		re = (re * 10) + (*p - '0');
		if (re > 2147483647 && j == 1)
			return (-1);
		if (re > 2147483648 && j == -1)
			return (-1);
		p++;
	}
	return (1);
}

int	check_range_integer(char *argv[], int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_scope(argv[i]) == -1)
			return (0);
		i++;
	}
	return (i);
}

int	empty_matrix(char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
