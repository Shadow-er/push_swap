/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   General_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:25:41 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:28:47 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temporary(t_rot **p, t_rot **dst)
{
	int	i;

	i = 0;
	*p = (t_rot *)malloc(sizeof(t_rot));
	init(p);
	if (*p == 0)
		return ;
	(*p)->content = ft_intdup((*dst)->content, (*dst)->top);
	(*p)->top = (*dst)->top;
	(*p)->size = (*p)->top;
}

int	ft_isset(char str, char Setter)
{
	if (Setter == str)
		return (1);
	return (0);
}

int	nbrlen(char *str, char charset)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[i])
	{
		while (ft_isset(str[i], charset) == 1)
			i++;
		if (str[i])
			l++;
		while (ft_isset(str[i], charset) == 0 && str[i])
			i++;
	}
	return (l);
}

int	min_int(t_rot **dst)
{
	int	i;
	int	min;

	i = 0;
	min = (*dst)->content[0];
	while (i < (*dst)->top)
	{
		if (min > (*dst)->content[i + 1])
			min = (*dst)->content[i + 1];
		i++;
	}
	return (min);
}
