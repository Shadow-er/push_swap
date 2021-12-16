/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Binary_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:49:30 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 06:50:02 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int max_bits(t_rot **dst)
{
	int	i;
	int max;

	i = 0;
	max = max_int(dst);
	while (max / 2)
	{
		i++;
	}
	return (i);
}

void	binary_op(t_rot **dst, t_rot **src)
{
	int max_b;
	int temp;
	int i;
	int	j;

	max_b = max_bits(dst);
	i = 0;
	while(is_sorted(dst) != 1)
	{
		j = 0;
		while(j <= (*dst)->top)
		{
			temp = (*dst)->content[j];
			if((temp >> i)&1 == 1)
				ra(dst);
			else
				pb(dst,src);
			j++;
		}
		i++;
		while(is_empty(*src) != 0)
			pa(dst,src);
	}
}
