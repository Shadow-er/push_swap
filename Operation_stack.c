/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:25:41 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/15 10:34:14 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_rot **l)
{	
	*l = NULL;
	(*l)->top = -1;
	(*l)->size = 0;
}

int	length(int *s1, int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		i++;
	}
	return (i);
}
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

void	copy(int *p, int *s)
{
	int	j;

	j = 0;
	while (s[j])
		{
			p[j] = s[j];
			j++;
		}
}
void allocate_int(t_rot **l,int argc,char **argv)
{
	int	i;
	
	(*l)->content = (int *)malloc(sizeof(int) * argc );
	if((*l)->content == 0)
		return ;
	fill(l,argv,argc);
	
	
}
void	fill_all(t_rot **l, char **argv, int size,int argc)
{
	int		c;
	int		i;
	char	*temp;

	if (size == 0)
		return ;
	i = 0;
	init(*l);
	while (i < size)
	{
		(*l)->content[i] = ft_atoi(argv[argc--]);
		((*l)->top) += 1;
		((*l)->size) += 1;
		i++;
	}	
}

int	is_empty(t_list *l)
{
	if (l->top == -1)
		return (0);
	return (1);
}