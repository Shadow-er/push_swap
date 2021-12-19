/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   General_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 07:12:39 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/19 10:17:31 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_rot *l)
{
	if (l->top == -1)
		return (0);
	return (1);
}

int	length(int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		i++;
	}
	return (i);
}

void suppress_element(t_rot **src , int a)
{
	int	i;
	t_rot *temp;

	i =0;
	temporary(&temp,src);
	free(*src);
	*src =(t_rot *)malloc(sizeof(t_rot));
	if(!src)
		return ;
	while(i <= (temp)->top)
	{
		if ((temp)->content[i] != a)
			(*src)->content[i]= (temp)->content[i];
		i++;
	}
	(*src)->top = (*src)->top - 1;
	free(temp);
}

int find_index(t_rot **dst, int a)
{
	int	i;

	i = 0;
	while(i <= (*dst)->top)
	{
		if((*dst)->content[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int max_int(t_rot **dst)
{
	int	i;
	int max;

	i = 0;
	max = (*dst)->content[0];
	while (i <= (*dst)->top - 1)
	{
		if ((*dst)->content[i] < (*dst)->content[i + 1])
			max = (*dst)->content[i + 1];
		i++;
	}
	return (max);
}