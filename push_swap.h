/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:27:29 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/22 13:33:05 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "Get_next_line/get_next_line.h"

void	init(t_rot **l);
int		sa(t_rot **l);
int		*ft_intdup(int *s1, int n);
int		sb(t_rot **s);
void	rra(t_rot **dst);
int		extract_content(t_rot **t);
void	add_content(t_rot **t, int a);
int		pa(t_rot **dst, t_rot **src);
int		pb(t_rot **dst, t_rot **src);
void	temporary(t_rot **p, t_rot **dst);
void	sort(t_rot **dst);
void	ichange(t_rot **dst);
int		max_int(t_rot **dst);
int		min_int(t_rot **dst);
int		max_bits(t_rot **dst);
void	suppress_element(t_rot **src, int a);
int		is_sorted(t_rot **dst);
void	binary_op(t_rot **dst, t_rot **src);
void	ra(t_rot **dst);
void	richange(t_rot **src, t_rot **original);
void	radix_sort(t_rot **dst, t_rot **src);
void	init(t_rot **l);
int		length(int n);
void	sort_2(t_rot **dst);
int		*ft_intdup(int *s1, int n);
void	allocate_int(t_rot **l, int argc, char **argv, t_rot **l2);
void	fill_all(t_rot **l, char **argv, int size);
int		find_index(t_rot **dst, int a);
int		is_empty(t_rot *l);
int		check_integer(char *argv[], int argc, int i, int j);
int		check_duplicata(char *argv[], int argc);
int		check_scope(char *argv);
int		check_range_integer(char *argv[], int argc);
int		ft_isset(char str, char Setter);
int		nbrlen(char *str, char charset);
int		minimum(t_rot **dst);
void	sort_5(t_rot **dst, t_rot **src);
void	sort_3(t_rot **dst);
void	add_content_b(t_rot **src, int a);
void	check_error(char *argv[], int argc);
int		empty_matrix(char *argv[], int argc);
int		empty_matrix(char *argv[], int argc);
int		is_sorted_half(t_rot **dst);
void	binary_op_v2(t_rot **dst, t_rot **src);
#endif