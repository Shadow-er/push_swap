/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_opeartion2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:40:28 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 11:42:50 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_rot **dst)
{
	int	i;
	int	temp;

	i = (*dst)->top;
	temp = (*dst)->content[(*dst)->top];
	while ( i >= 0)
	{
		if (i != 0)
		{
			(*dst)->content[i] = (*dst)->content[i - 1];
		}
		else if (i == 0)
			(*dst)->content[0] = temp;
		i--;
	}
	ft_putstr_fd("rra\n",1);
}

void	rrb(t_rot **dst)
{
	int	i;
	int	temp;

	i = (*dst)->top;
	temp = (*dst)->content[(*dst)->top];
	while ( i >= 0)
	{
		if (i != 0)
		{
			(*dst)->content[i] = (*dst)->content[i - 1];
		}
		else if (i == 0)
			(*dst)->content[0] = temp;
		i--;
	}
	ft_putstr_fd("rrb\n",1);
}

void	rrr(t_rot **dst,t_rot **src)
{
	rra(dst);
	rrb(src);
}

void	rb(t_rot **dst)
{
	int	i;
	int	save;
	int temp;

	save = (*dst)->top;
	i = 0;
	temp = (*dst)->content[0];
	while (i <= (*dst)->top)
	{
		if (i != (*dst)->top)
			(*dst)->content[i] = (*dst)->content[i + 1];
		else if(i == (*dst)->top)
			(*dst)->content[i] = temp;
		i++;
	}
	ft_putstr_fd("rb\n",1);
}

void	rr(t_rot **dst, t_rot **src)
{
	ra(dst);
	rb(src);
}
