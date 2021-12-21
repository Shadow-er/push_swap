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
int	sa_n(t_rot **s)
{
	int	i;
	int	temp;

	if ((*s)->top < 1)
		return (0);
	temp = (*s)->content[0];
	(*s)->content[0] = (*s)->content[1];
	(*s)->content[1] = temp;
	i = 1;
	return (i);
}
int	pa_n(t_rot **dst, t_rot **src)
{
	int	i;

	if ((*src)->top == -1)
		return (0);
	i = extract_content(src);
	add_content(dst, i);
	return (1);
}

int	pb_n(t_rot **dst, t_rot **src)
{
	int	i;

	if ((*dst)->top == -1)
		return (0);
	i = extract_content(dst);
	add_content_b(src, i);
	return (1);
}
void	ra_n(t_rot **dst)
{
	int	i;
	int	save;
	int temp;

	save = (*dst)->top;
	i = 0;
	temp = (*dst)->content[0];
	while (i <= (*dst)->top)
	{
		if (i != (*dst)->top)
			(*dst)->content[i] = (*dst)->content[i + 1];
		else if(i == (*dst)->top)
			(*dst)->content[i] = temp;
		i++;
	}
}
void	rra_n(t_rot **dst)
{
	int	i;
	int	temp;

	i = (*dst)->top;
	temp = (*dst)->content[(*dst)->top];
	while ( i >= 0)
	{
		if (i != 0)
		{
			(*dst)->content[i] = (*dst)->content[i - 1];
		}
		else if (i == 0)
			(*dst)->content[0] = temp;
		i--;
	}
}
void	error_check(char *argv[], int argc)
{
	if (empty_matrix(argv, argc) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_integer(argv, argc, 1,0) == 0))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	if ((check_duplicata(argv, argc)) == 0)
	{
		ft_putstr_fd("Error\n",2);
		exit(-1);
	}
	if ((check_range_integer(argv, argc) == 0))
	{
		ft_putstr_fd("Error\n",2);
		exit(-1);
	}
}
int main(int  argc, char *argv[])
{
	char	*s;
	int		i;
	t_rot *l;
	t_rot *r;

	l = (t_rot *)malloc(sizeof(t_rot));
	r = (t_rot *)malloc(sizeof(t_rot));
	l->content = (int*)malloc(sizeof(int)*(argc - 1));
	r->content = (int*)malloc(sizeof(int)*(argc - 1));
	i = 0;
	while(i < argc - 1)
	{
		l->content[i] = ft_atoi((const char *)argv[i + 1]);
		i++;
	}
	l->top = argc - 2;
	r->top = -1;
	r->size = (argc - 1);
	error_check(argv,argc);
	s = get_next_line(0);
	while (s != 0)
	{
		if (ft_strcm(s,"sa\n") == 0)
			sa_n(&l);
		if (ft_strcm(s,"ra\n") == 0)
			ra_n(&l);
		if (ft_strcm(s,"rra\n") == 0)
			rra_n(&l);
		if (ft_strcm(s,"pa\n") == 0)
			pa_n(&l,&r);
		if (ft_strcm(s,"pb\n") == 0)
			pb_n(&l,&r);
		s = get_next_line(0);
	}
	if (is_sorted(&l) == 1)
		printf("OK");
	else
		printf("KO");
	
}
