/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:46:34 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:30:46 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_error(char *argv[], int argc)
{
	if (empty_matrix(argv, argc) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_integer(argv, argc, 1, 0) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_duplicata(argv, argc)) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_range_integer(argv, argc) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}

void	ss(t_rot **s, t_rot **b)
{	
	sa(s);
	sb(b);
}
