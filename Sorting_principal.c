/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_principal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:50:21 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:45:40 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_rot **dst)
{
	int	i;

	i = 0;
	while (i < (*dst)->top)
	{
		if ((*dst)->content[i] > (*dst)->content[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_2(t_rot **dst)
{
	if ((*dst)->content[0] > (*dst)->content[1])
		sa(dst);
}

void	sort_3(t_rot **dst)
{
	if ((*dst)->content[0] < (*dst)->content[1]
		&& ((*dst)->content[1] > (*dst)->content[2])
		&& (*dst)->content[0] < (*dst)->content[2])
	{
		sa(dst);
		ra(dst);
	}
	else if ((*dst)->content[0] > (*dst)->content[1]
		&& ((*dst)->content[1] < (*dst)->content[2])
		&& (*dst)->content[0] > (*dst)->content[2])
		ra(dst);
	else if ((*dst)->content[0] > (*dst)->content[1]
		&& (*dst)->content[1] > (*dst)->content[2])
	{
		sa(dst);
		rra(dst);
	}
	else if ((*dst)->content[0] > (*dst)->content[1]
		&& ((*dst)->content[1] < (*dst)->content[2])
		&& ((*dst)->content[0] < (*dst)->content[2]))
		sa(dst);
	else if ((*dst)->content[0] < (*dst)->content[1]
		&& ((*dst)->content[1] > (*dst)->content[2])
		&& (*dst)->content[0] > (*dst)->content[2])
		rra(dst);
}

void	sort_5(t_rot **dst, t_rot **src)
{
	int	i;
	int	j;

	i = 0;
	while ((*dst)->top > 2)
	{
		j = min_int(dst);
		if (minimum(dst) == 1)
		{
			while ((*dst)->content[0] != j)
				rra(dst);
		}
		else
		{
			while ((*dst)->content[0] != j)
				ra(dst);
		}
		pb(dst, src);
	}
	if ((*dst)->top == 2)
	{
		sort_3(dst);
		pa(dst, src);
		pa(dst, src);
	}
}

void	radix_sort(t_rot **dst, t_rot **src)
{
	t_rot	*temp;

	temporary(&temp, dst);
	ichange(&temp);
	binary_op(&temp, src);
	free(temp->content);
	free(temp);
}
