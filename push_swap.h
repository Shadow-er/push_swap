/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:27:29 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/15 08:27:02 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define   PUSH_SWAP_H
# include "libft/libft.h"

void init(t_rot **l);
int sa(t_rot **l);
void	copy(char *p, char *s);
int	*ft_intdup(int *s1, int n);
int	length(const int *s1, int n);
int	sa(t_rot **s);
int	extract_content(t_rot **t);
void	add_content(t_rot **t, int a);
int	pa(t_rot **dst, t_rot **src);
int	pb(t_rot **dst, t_rot **src);
void temporary(t_rot **p, t_rot **dst);
t_rot *sort(t_rot **dst);
void ichange(t_rot **dst);
int max_int(t_rot **dst);
int min_int(t_rot **dst);
int max_bits(t_rot **dst);
void suppress_element(t_rot **src , int a);
int is_sorted(t_rot **dst);
void	binary_op(t_rot **dst, t_rot **src);
void	ra(t_rot **dst);
void richange(t_rot **src,t_rot **original);
void radix_sort(t_rot **dst, t_rot **src);
void	init(t_rot **l);
int	length(int *s1, int n);
int	*ft_intdup(int *s1, int n);
void	copy(int *p, int *s);
void allocate_int(t_rot **l,int argc,char **argv);
void	fill_all(t_rot **l, char **argv, int size);
int	is_empty(t_list *l);

#endif