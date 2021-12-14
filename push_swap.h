/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:27:29 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/14 15:20:58 by mlakhssa         ###   ########.fr       */
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

#endif