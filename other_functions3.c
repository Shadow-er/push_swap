/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:59:35 by mlakhssa          #+#    #+#             */
/*   Updated: 2022/01/03 10:51:09 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

void	rrb_n(t_rot **dst)
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

void	rrr_n(t_rot **dst, t_rot **src)
{
	rra_n(dst);
	rrb_n(src);
}

void	rb_n(t_rot **dst)
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

void	rr_n(t_rot **dst, t_rot **src)
{
	ra_n(dst);
	rb_n(src);
}
