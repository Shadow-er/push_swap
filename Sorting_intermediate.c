/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_intermediate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:57:32 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:44:56 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_rot **dst)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i <= (*dst)->top)
	{
		j = 0;
		while (j <= (*dst)->top - 1)
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
}

int	min_int_index(t_rot **dst, int start)
{
	int	i;
	int	min;

	i = start;
	min = 0;
	while (i < (*dst)->top)
	{
		if ((*dst)->content[min] > (*dst)->content[i + 1])
			min = i + 1;
		i++;
	}
	return (min);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ichange(t_rot **dst)
{
	t_rot	*sorted;
	int		i;
	int		j;

	temporary(&sorted, dst);
	sort(&sorted);
	i = 0;
	while (i <= (*dst)->top)
	{
		j = 0;
		while (j <= sorted->top)
		{
			if ((sorted)->content[j] == (*dst)->content[i])
			{
				(*dst)->content[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted->content);
	free(sorted);
}

int	minimum(t_rot **dst)
{
	int	i;
	int	size;
	int	min;

	size = ((*dst)->top) / 2;
	min = min_int(dst);
	i = find_index(dst, min);
	if (i >= size)
		return (1);
	return (0);
}
