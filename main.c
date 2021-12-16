/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:15:06 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 10:37:14 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int empty_matrix(char *argv[],int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if(argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	check_error(char *argv[], int argc)
{
	if (empty_matrix(argv, argc) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_integer(argv, argc, 1,0) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_duplicata(argv, argc)) == 0)
	{
		ft_putstr_fd("Error\n",2);
		exit(-1);
	}
	if ((check_range_integer(argv, argc) == 0))
	{
		ft_putstr_fd("Error\n",2);
		exit(-1);
	}
}
int main(int argc, char *argv[])
{
	int	i;
	
	check_error(argv,argc);
	// t_rot *l;
	// if(argc >= 2)
	// {
	// 	allocate_int(&l, argc - 1 , argv);
	// 	printf("%s",l->content);
	// }
	return (0);
}