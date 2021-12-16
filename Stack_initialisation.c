/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:54:23 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 06:56:15 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_rot **l)
{	
	*l = NULL;
	(*l)->top = -1;
	(*l)->size = 0;
}

void	fill_all(t_rot **l, char **argv, int size,int argc)
{
	int		c;
	int		i;
	char	*temp;

	if (size == 0)
		return ;
	i = 0;
	init(*l);
	while (i < size)
	{
		(*l)->content[i] = ft_atoi(argv[argc--]);
		((*l)->top) += 1;
		((*l)->size) += 1;
		i++;
	}	
}

void allocate_int(t_rot **l,int argc,char **argv)
{
	int	i;

	(*l)->content = (int *)malloc(sizeof(int) * argc );
	if((*l)->content == 0)
		return ;
	fill_all(l,argv,argc,argc);
}