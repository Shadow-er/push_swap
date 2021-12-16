/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting_principal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:50:21 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 06:57:28 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_rot **dst)
{
	int	i;

	i = 0;
	while(i <= (*dst)->top - 1)
	{
		if((*dst)->content[i] > (*dst)->content[i + 1])
			return (0);
	}
	return (1);
}

void sort_3_part1(t_rot **dst)
{
	
	if ((*dst)->content[0] < (*dst)->content[1] 
		&& ((*dst)->content[1] < (*dst)->content[2]))
	{
		if((*dst)->content[0] < (*dst)->content[2])
			{
				sa(dst);
				rra(dst);
			}
	}
	if((*dst)->content[0] > (*dst)->content[1])
	{
		if((*dst)->content[1] < (*dst)->content[2])
				ra(dst);
	}
}
void sort_3_part2(t_rot **dst)
{
	if((*dst)->content[0] > (*dst)->content[1])
	{
		if((*dst)->content[1] > (*dst)->content[2])
			{
				sa(dst);
				rra(dst);
			}
	}
	if ((*dst)->content[0] < (*dst)->content[1] 
		&& ((*dst)->content[1] > (*dst)->content[2]))
	{
		if((*dst)->content[1] > (*dst)->content[2])
				rra(dst);
	}
	if ((*dst)->content[0] > (*dst)->content[1] 
		&& ((*dst)->content[1] < (*dst)->content[2]))
	{
				sa(dst);
	}
}
void sort_5(t_rot **dst, t_rot **src)
{
	int	i;

	i = 0;
	while (!is_sorted(dst) || (*dst)->top == 3)
	{	
		if (minimum(dst) == 1)
			rra(dst,src);
		else
			ra(dst);
		if ((*dst)->content[0] == min_int(dst))
			pa(dst,src);
	}
	if (!is_sorted(dst))
	{
		sort_3_part1(dst);
		sort_3_part2(dst);
		pb(dst,src);
		pb(dst,src);	
	}
}

void radix_sort(t_rot **dst, t_rot **src)
{
	t_rot	*temp;
	t_rot	*temp2;
	int	i;
	
	temporary(&temp,dst);
	temporary(&temp2,dst);
	ichange(&temp);
	binary_op(&temp,src);
	richange(&temp,&temp2);
	free((*dst)->content);
	(*dst)->content = ft_intdup(temp->content,temp->top);
	(*dst)->top = temp->top;
}