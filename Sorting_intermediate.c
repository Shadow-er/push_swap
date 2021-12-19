/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_intermediate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:57:32 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/19 10:23:56 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rot *sort(t_rot **dst)
{
	int	i;
	int j;
	int temp;
	t_rot *p;

	i = 0;
	while(i <= (*dst)->top )
	{
		j = 0;
		while(j <= (*dst)->top - 1)
		{
			if ((*dst)->content[j] > (*dst)->content[j + 1])
				{
					temp = (*dst)->content[j];
					(*dst)->content[j] = (*dst)->content[j + 1];
					(*dst)->content[j + 1] = temp;
				}
			j++;
		}
		i++;
	}
	temporary(&p,dst);
	return (p);
}

void ichange(t_rot **dst)
{
	int	i;

	i = 0;
	while(i <= (*dst)->top )
	{
		(*dst)->content[i] = i;
		i++;
	}
}

void richange(t_rot **src,t_rot **original)
{
	int i;
	int min;
	int j;

	i = 0;
	min = min_int(original);
	while(i <= (*src)->top)
	{
		j = 0;
		min = min_int(original);
		while(j <= (*original)->top)
		{
			if ((*original)->content[j] == min)
				{
					(*src)->content[i] = (*original)->content[j];
					suppress_element(original,min);
					break;
				}
			j++;
		}
		i++;
	}
}

int minimum(t_rot **dst)
{
	int	i;
	int	size;
	int	min;

	size = ((*dst)->top)/2;
	min = min_int(dst);
	i = find_index(dst, min);
	if(i >= size)
		return (1);
	return (0);			
}