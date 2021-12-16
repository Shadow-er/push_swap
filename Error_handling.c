/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:33:36 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 07:54:01 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_integer(char *argv[],int argc)
{
	int	i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				return (0);
			while(ft_isdigit(argv[i][j]))
				j++;
			if(!ft_isdigit(argv[i][j]))
				return (0);
		}
		i++;
	}	
	return(1);
}
int check_duplicata(char *argv[],int argc)
{
	int i;
	int j;

	i = 0;
		while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (i == j)
				j++;
			if(ft_strstr(argv[i],argv[j]) ==1)
				return (0);
			j++;
		}
		i++;
	}	
	return(1);
}

int check_scope(char *argv)
{
	unsigned long long	re;
	int					j;
	char				*p;

	j = 1;
	re = 0;
	p = (char *)argv;
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
int check_range_integer(char *argv[],int argc)
{
	int i;
	
	i = 0;
	while (i < argc)
	{
		if(check_scope(argv[i]) == -1)
			return (0);
		i++;
	}
	return (i);
}