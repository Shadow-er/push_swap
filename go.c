/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:15:06 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/21 13:24:14 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void do_it(t_rot *l, int argc, char *argv[], t_rot *stack2)
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
		do_it(l,argc,argv,stack2);
	free(l->content);
	free(l);
	free(stack2->content);
	free(stack2);
	return (0);
}