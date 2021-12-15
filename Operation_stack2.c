/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhssa <mlakhssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:59:19 by mlakhssa          #+#    #+#             */
/*   Updated: 2021/12/15 14:00:00 by mlakhssa         ###   ########.fr       */
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
	i = extract_content(dst);
	add_content(src, i);
	return (1);
}
void temporary(t_rot **p, t_rot **dst);
{
	int i;

	i = 0;
	init(&*p);
	*p = (t_rot *)malloc(sizeof(t_rot));
	if(*p == 0)
		return ;
	(*p)->content = ft_intdup((*dst)->content,(*dst)->top);
	(*p)->top = (*dst)->top;
	(*p)->size = (*p)->top; 
}
t_rot *sort(t_rot **dst)
{
	int	i;
	int j;
	int temp;
	t_rot *p;

	i = 0;
	while(i < (*dst)->top - 1)
	{
		j = 0;
		while(j < (*dst)->top - 2)
		{
			if ((*dst)->content[j] > (*dst)->content[j + 1])
				{
					temp = (*dst)->content[j];
					(*dst)->content[j] = (*dst)->content[j + 1];
					(*dst)->content[j + 1] = temp;
				}
			j++;
		}
		i++;
	}
	temporary(&p,dst);
	return (p);
}

void ichange(t_rot **dst)
{
	int	i;

	i = 0;
	while(i < (*dst)->top - 2)
	{
		(*dst)->content[i] = i;
		i++;
	}
}
int max_int(t_rot **dst)
{
	int	i;
	int max;

	i = 0;
	max = (*dst)->content[0];
	while (i < (*dst)->top - 2)
	{
		if ((*dst)->content[i] < (*dst)->content[i + 1])
			max = (*dst)->content[i + 1];
		i++;
	}
	return (max);
}
int min_int(t_rot **dst)
{
	int	i;
	int min;

	i = 0;
	min = (*dst)->content[0];
	while (i < (*dst)->top - 2)
	{
		if ((*dst)->content[i] > (*dst)->content[i + 1])
			min = (*dst)->content[i + 1];
		i++;
	}
	return (min);
}
int max_bits(t_rot **dst)
{
	int	i;
	int max;

	i = 0;
	max = max_int(dst);
	while (max / 2)
	{
		i++;
	}
	return (i);
}
void suppress_element(t_rot **src , int a)
{
	int	i;
	t_rot **temp;

	i =0;
	temporary(temp,src);
	free(*src);
	*src =(t_rot *)malloc(sizeof(t_rot));
	if(!src)
		return ;
	while(i <= (*temp)->top)
	{
		if ((*temp)->content[i] != a)
			(*src)->content[i]= (*temp)->content[i];
		
	}
	(*src)->top = (*src)->top - 1;
	free(temp);
}

int is_sorted(t_rot **dst)
{
	int	i;

	i = 0;
	while(i <= (*dst)->top - 1)
	{
		if((*dst)->content[i] > (*dst)->content[i + 1])
			return (0);
	}
	return (1);
}
void sort_3_part1(t_rot **dst)
{
	
	if ((*dst)->content[0] < (*dst)->content[1] 
		&& ((*dst)->content[1] < (*dst)->content[2]))
	{
		if((*dst)->content[0] < (*dst)->content[2])
			{
				sa(dst);
				rra(dst);
			}
	}
	if((*dst)->content[0] > (*dst)->content[1])
	{
		if((*dst)->content[1] < (*dst)->content[2])
				ra(dst);
	}
}
void sort_3_part2(t_rot **dst)
{
	if((*dst)->content[0] > (*dst)->content[1])
	{
		if((*dst)->content[1] > (*dst)->content[2])
			{
				sa(dst);
				rra(dst);
			}
	}
	if ((*dst)->content[0] < (*dst)->content[1] 
		&& ((*dst)->content[1] > (*dst)->content[2]))
	{
		if((*dst)->content[1] > (*dst)->content[2])
				rra(dst);
	}
	if ((*dst)->content[0] > (*dst)->content[1] 
		&& ((*dst)->content[1] < (*dst)->content[2]))
	{
				sa(dst);
	}
}
int find_index(t_rot **dst, int a)
{
	int	i;

	i = 0;
	while(i < (*dst)->top)
	{
		if((*dst)->content[i] == a)
			return (i);
	}
}

int minimun(t_rot **dst)
{
	int	i;
	int	size;
	int	min;

	size = ((*dst)->top)/2;
	min = min_int(dst);
	i = find_index(dst, min);
	if(i >= size)
		return (1);
	if(i < size)
		return (0);			
}

void sort_5(t_rot **dst, t_rot **src)
{
	int	i;

	i = 0;
	while (!is_sorted(dst) || (*dst)->top == 3)
	{	
		if (minimum(dst) == 1)
			rra(dst,src);
		else
			ra(dst);
		if ((*dst)->content[0] == min_int(dst))
			pa(dst,src);
	}
	if (!is_sorted(dst))
	{
		sort_3_part1(dst);
		sort_3_part2(dst);
		pb(dst,src);
		pb(dst,src);	
	}
}

void	binary_op(t_rot **dst, t_rot **src)
{
	int max_b;
	int temp;
	int i;
	int	j;

	max_b = max_bits(dst);
	i = 0;
	while(is_sorted(dst) != 1)
	{
		j = 0;
		while(j < (*dst)->top - 1)
		{
			temp = (*dst)->content[j];
			if((temp >> i)&1 == 1)
				ra(dst);
			else
				pb(dst,src);
			j++;
		}
		i++;
	
		while(is_empty(*src) != 0)
			pa(dst,src);
	}
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

void richange(t_rot **src,t_rot **original)
{
	int i;
	int min;

	i = 0;
	min = min_int(original);
	while(i <= (*src)->top)
	{
		j = 0;
		min = min_int(original);
		while(j <= (*original)->top)
		{
			if ((*original)->content[j] == min)
				{
					(*src)->content[i] = (*original)->content[j];
					suppress_element(original,min);
					break;
				}
			j++;
		}
		i++;
	}
}

void radix_sort(t_rot **dst, t_rot **src)
{
	t_rot	*temp;
	t_rot	*temp2;
	int	i;
	
	temporary(&temp,dst);
	temporary(&temp2,dst);
	ichange(&temp);
	binary_op(&temp,src);
	richange(&temp,&temp2);
	free((*dst)->content);
	(*dst)->content = ft_intdup(temp->content,temp->top);
	(*dst)->top = temp->top;
}