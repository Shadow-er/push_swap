/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:48:22 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:46:17 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sa_n(t_rot **s)
{
	int	i;
	int	temp;

	if ((*s)->top < 1)
		return (0);
	temp = (*s)->content[0];
	(*s)->content[0] = (*s)->content[1];
	(*s)->content[1] = temp;
	i = 1;
	return (i);
}

int	pa_n(t_rot **dst, t_rot **src)
{
	int	i;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(src);
	add_content(dst, i);
	return (1);
}

int	pb_n(t_rot **dst, t_rot **src)
{
	int	i;

	if ((*dst)->top == -1)
		return (0);
	i = extract_content(dst);
	add_content_b(src, i);
	return (1);
}

void	ra_n(t_rot **dst)
{
	int	i;
	int	save;
	int	temp;

	save = (*dst)->top;
	i = 0;
	temp = (*dst)->content[0];
	while (i <= (*dst)->top)
	{
		if (i != (*dst)->top)
			(*dst)->content[i] = (*dst)->content[i + 1];
		else if (i == (*dst)->top)
			(*dst)->content[i] = temp;
		i++;
	}
}

void	rra_n(t_rot **dst)
{
	int	i;
	int	temp;

	i = (*dst)->top;
	temp = (*dst)->content[(*dst)->top];
	while (i >= 0)
	{
		if (i != 0)
		{
			(*dst)->content[i] = (*dst)->content[i - 1];
		}
		else if (i == 0)
			(*dst)->content[0] = temp;
		i--;
	}
}
