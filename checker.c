/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:16:53 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:18:21 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_strcm(char *s1, char *s2)
{
	unsigned char	*s;
	unsigned char	*p;

	s = (unsigned char *)s1;
	p = (unsigned char *)s2;
	while (*s == *p && *s && *p)
	{
		s++;
		p++;
	}
	return (*s - *p);
}

void	error_check(char *argv[], int argc)
{
	if (empty_matrix(argv, argc) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_integer(argv, argc, 1, 0) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_duplicata(argv, argc)) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_range_integer(argv, argc) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
}

void	go_check(t_rot **l, t_rot **r, char *s)
{
	if (ft_strcm(s, "sa\n") == 0)
		sa_n(l);
	if (ft_strcm(s, "ra\n") == 0)
		ra_n(l);
	if (ft_strcm(s, "rb\n") == 0)
		rb_n(l);
	if (ft_strcm(s, "rr\n") == 0)
		rr_n(l);
	if (ft_strcm(s, "rra\n") == 0)
		rra_n(l);
	if (ft_strcm(s, "rrb\n") == 0)
		rrb_n(l);
	if (ft_strcm(s, "rrr\n") == 0)
		rrr_n(l);
	if (ft_strcm(s, "pa\n") == 0)
		pa_n(l, r);
	if (ft_strcm(s, "pb\n") == 0)
		pb_n(l, r);
}

void	inialize(t_rot **l, t_rot **r, int argc)
{
	*l = (t_rot *)malloc(sizeof(t_rot));
	*r = (t_rot *)malloc(sizeof(t_rot));
	(*l)->content = (int *)malloc(sizeof(int) * (argc - 1));
	(*r)->content = (int *)malloc(sizeof(int) * (argc - 1));
	(*l)->top = argc - 2;
	(*r)->top = -1;
	(*r)->size = (argc - 1);
}

int	main(int argc, char *argv[])
{
	char	*s;
	int		i;
	t_rot	*l;
	t_rot	*r;

	i = 0;
	inialize(&l, &r, argc);
	while (i < argc - 1)
	{
		l->content[i] = ft_atoi((const char *)argv[i + 1]);
		i++;
	}	
	error_check(argv, argc);
	s = get_next_line(0);
	while (s != 0)
	{
		go_check(&l, &r, s);
		s = get_next_line(0);
	}
	if (is_sorted(&l) == 1)
		printf("OK");
	else
		printf("KO");
	return (0);
}
