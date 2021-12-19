/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:15:06 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/19 16:57:53 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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
	
	check_error(argv,argc);
	t_rot *l;
	t_rot *stack2;
	int i;
	
	i = 0;
	l = (t_rot *)malloc(sizeof(t_rot));
	if (l == 0)
		return (0);
	stack2 = (t_rot *)malloc(sizeof(t_rot));
	if (stack2 == 0)
		return (0);
	if(argc >= 3)
	{
		allocate_int(&l, argc - 1 , argv, &stack2);
		if (is_sorted(&l))
			exit(0);
		if (argc == 3)
			sort_2(&l);
		else if (argc == 4)
			sort_3(&l);
		else if (argc == 6 || argc == 5)
			sort_5(&l,&stack2);
		else if (argc > 6)
			radix_sort(&l,&stack2);
	}
	free(l->content);
	free(l);
	free(stack2->content);
	free(stack2);
	system("leaks push_swap");
	return (0);
}