/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:54:23 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/19 11:08:29 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_rot **l)
{	
	//*l = NULL;
	(*l)->top = -1;
	(*l)->size = 0;
}

void	fill_all(t_rot **l, char **argv, int size)
{
	int	i;
	int	j;

	j = 1;
	if (size == 0)
		return ;
	i = 0;
	init(l);
	while (i < size)
	{
		(*l)->content[i] = ft_atoi(argv[j]);
		((*l)->top) += 1;
		((*l)->size) += 1;
		i++;
		j++;
	}	
}

void allocate_int(t_rot **l,int argc,char **argv,t_rot **l2)
{
	(*l)->content = (int *)malloc(sizeof(int) * argc);
	if((*l)->content == 0)
		return ;
	fill_all(l,argv,argc);
	(*l2)->content = (int *)malloc(sizeof(int) * argc);
	if((*l2)->content == 0)
		return ;
	(*l2)->size = argc;
	(*l2)->top = -1;
}