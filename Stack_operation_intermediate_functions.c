/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_operation_intermediate_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:52:38 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 06:53:31 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_intdup(int *s1, int n)
{
	int	r;
	int	i;
	int	*dst;

	r = length(s1, n);
	dst = (int *)malloc(sizeof(int) * r);
	if (dst == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	return (dst);
}

int	extract_content(t_rot **t)
{
	int	i;
	int	j;
	int	*p;

	j = (*t)->content[0];
	p = (int *)malloc(sizeof(int) * ((*t)->top) - 1);
	i = 0;
	while (i <= (*t)->top - 1)
	{
		p[i] = (*t)->content[i + 1];
		i++;
	}
	free((*t)->content);
	(*t)->top = i;
	ft_intdup((*t)->content, (*t)->top);
	free(p);
	return (j);
}

void	add_content(t_rot **t, int a)
{
	int	i;
	int	j;
	int	*p;

	p = (int *)malloc(sizeof(int) * ((*t)->top) + 1);
	i = 0;
	j = 1;
	p[0] = a;
	while (i <= (*t)->top)
	{
		p[j] = (*t)->content[i];
		i++;
		j++;
	}
	free((*t)->content);
	(*t)->top = i + 1;
	ft_intdup((*t)->content, (*t)->top);
	free(p);
}