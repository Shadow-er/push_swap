/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:47:07 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 07:52:24 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("sa\n",1);
	return (i);
}
int	pa(t_rot **dst, t_rot **src)
{
	int	i;
	int	*temp;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(src);
	add_content(dst, i);
	ft_putstr_fd("pa\n",1);
	return (1);
}

int	pb(t_rot **dst, t_rot **src)
{
	int	i;
	int	*temp;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(dst);
	add_content(src, i);
	ft_putstr_fd("pb\n",1);
	return (1);
}
void	ra(t_rot **dst)
{
	int	i;
	int	save;

	save = (*dst)->top;
	i = 0;
	while (i <= (*dst)->top)
	{
		(*dst)->content[i % save] = (*dst)->content[save - i];
	}
	ft_putstr_fd("ra\n",1);
}
void	rra(t_rot **dst)
{
	int	i;
	int	save;

	save = (*dst)->content[0];
	i = 0;
	while (i <= (*dst)->top)
	{
		if (i != (*dst)->top)
			(*dst)->content[i + 1] = (*dst)->content[i];
		else
			(*dst)->content[0] = (*dst)->content[i];
	}
	ft_putstr_fd("rra\n",1);
}