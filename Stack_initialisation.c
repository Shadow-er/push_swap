/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:54:23 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/16 11:26:45 by mlakhssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_rot **l)
{	
	*l = NULL;
	(*l)->top = -1;
	(*l)->size = 0;
}

char *join_matrix(char **argv,int argc)
{
	char **final;
	char *temp;
	char	*fin;
	int		i;
	int		j;

	i = 0;
	while(i < argc)
	{
		final = ft_split(argv[i],' ');
		j = 0;
		if(final[j + 1])
		{
			while(!final[j + 1])
			{
				temp = ft_strjoin((char const *)final[j],' ');
				fin = ft_strjoin((char const *)temp,(char const *)final[j + 1]);
				j++;
			}
		}
		else
			fin = ft_strdup((const char *)final[0]);
		i++;
	}
	return (fin);
}
char **new_matrix(char **argv,int argc)
{
	char	**final;
	int		i;
	int 	total;
	char	*temp;
	
	i = 1;
	total = 0;
	while(i < argc)
	{
		total += total + nbrlen(argv[0],' ');
		i++; 
	}
	i = 0;
	temp = join_matrix(argv,argc);
	ft_split(temp,' ');
}
void	fill_all(t_rot **l, char **argv, int size,int argc)
{
	int		c;
	int		i;
	char	*temp;

	if (size == 0)
		return ;
	i = 0;
	init(l);
	while (i < size)
	{
		(*l)->content[i] = ft_atoi(argv[argc--]);
		((*l)->top) += 1;
		((*l)->size) += 1;
		i++;
	}	
}

void allocate_int(t_rot **l,int argc,char **argv)
{
	int	i;

	(*l)->content = (int *)malloc(sizeof(int) * argc );
	if((*l)->content == 0)
		return ;
	fill_all(l,argv,argc,argc);
}