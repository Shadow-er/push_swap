/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:59:19 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/14 16:06:54 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"

int	sa(t_rot **s)
{
	int	i;
	int	temp;

	if ((*s)->top < 1)
		return (0);
	temp = (*s)->content[0];
	(*s)->content[0] = (*s)->content[1];
	(*s)->content = temp;
	i = 1;
	return (i);
}

int	extract_content(t_rot **t)
{
	int	i;
	int	j;
	int	*p;

	j = (*t)->content[0];
	p = (int *)malloc(sizeof(int) * ((*t)->size) - 1);
	i = 0;
	while (i < (*t)->top - 1)
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
	int	*p;

	p = (int *)malloc(sizeof(int) * ((*t)->size) + 1);
	i = 0;
	p[0] = a;
	while (i < (*t)->top - 1)
	{
		p[i + 1] = (*t)->content[i + 1];
		i++;
	}
	free((*t)->content);
	(*t)->top = i + 1;
	ft_intdup((*t)->content, (*t)->top);
	free(p);
}

int	pa(t_rot **dst, t_rot **src)
{
	int	i;
	int	*temp;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(src);
	add_content(dst, i);
	return (1);
}

int	pb(t_rot **dst, t_rot **src)
{
	int	i;
	int	*temp;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(src);
	add_content(dst, i);
	return (1);
}
void	itob(t_rot **dst)
{
	
}
void	ra(t_rot **dst)
{
	int	i;
	int	save;

	save = (*dst)->top;
	i = 0;
	while (i < (*dst)->top)
	{
		(*dst)->content[i % save] = (*dst)->content[save - i];
	}
}
void convert