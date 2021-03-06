/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Binary_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:49:30 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:35:16 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	max_bits(t_rot **dst)
{
	int	i;
	int	max;

	i = 0;
	max = max_int(dst);
	while (max != 0)
	{
		i++;
		max = max / 2;
	}
	return (i);
}

void	binary_op(t_rot **dst, t_rot **src)
{
	int	max_b;
	int	i;
	int	j;
	int	r;

	max_b = max_bits(dst);
	i = 0;
	while (!is_sorted(dst))
	{
		j = 0;
		while (j <= ((*dst)->size))
		{
			r = ((*dst)->content[0] >> i) & 1;
			if (r == 1)
			{	
				ra(dst);
			}
			else
				pb(dst, src);
			j++;
		}
		while (is_empty(*src) != 0)
			pa(dst, src);
		i++;
	}
}

void	richange(t_rot **src, t_rot **original)
{
	int	i;
	int	min;
	int	j;

	i = 0;
	min = min_int(original);
	while (i <= (*src)->top)
	{
		j = 0;
		min = min_int(original);
		while (j <= (*original)->top)
		{
			if ((*original)->content[j] == min)
			{
				(*src)->content[i] = (*original)->content[j];
				suppress_element(original, min);
				break ;
			}
			j++;
		}
		i++;
	}
}
