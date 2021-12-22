/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_operation_intermediate_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:52:38 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:41:06 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_intdup(int *s1, int n)
{
	int	i;
	int	*dst;

	dst = (int *)malloc(sizeof(int) * (n + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (i <= n)
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
	p = (int *)malloc(sizeof(int) * ((*t)->top));
	if (p == 0)
		return (0);
	i = 0;
	while (i < ((*t)->top))
	{
		p[i] = (*t)->content[i + 1];
		i++;
	}
	free((*t)->content);
	(*t)->top = i - 1;
	(*t)->content = ft_intdup(p, (*t)->top);
	free(p);
	return (j);
}

void	add_content(t_rot **t, int a)
{
	int	i;
	int	j;
	int	*p;

	j = (*t)->top + 2;
	p = (int *)malloc(sizeof(int) * j);
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
	(*t)->top = i;
	(*t)->content = ft_intdup(p, (*t)->top);
	free(p);
}

void	add_content_b(t_rot **src, int a)
{
	int	i;
	int	j;
	int	*p;

	p = (int *)malloc(sizeof(int) * ((*src)->size));
	i = 0;
	j = 1;
	p[0] = a;
	while (i <= (*src)->top)
	{
		p[j] = (*src)->content[i];
		i++;
		j++;
	}
	free((*src)->content);
	(*src)->top = i;
	(*src)->content = ft_intdup(p, (*src)->top);
	free(p);
}
