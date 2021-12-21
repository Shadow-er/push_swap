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
	// check_error(argv,argc);
	s = get_next_line(0);
	while (s != 0)
	{
		printf("%s",s);
		if (ft_strcm(s,"sa\n") == 0)
			sa(&l);
		if (ft_strcm(s,"ra\n") == 0)
			ra(&l);
		if (ft_strcm(s,"rra\n") == 0)
			rra(&l);
		if (ft_strcm(s,"pa\n") == 0)
			pa(&l,&r);
		if (ft_strcm(s,"pb\n") == 0)
			pb(&l,&r);
		s = get_next_line(0);
	}
	printf("%d",l->content[0]);
	printf("%d",l->content[1]);
	printf("%d",l->content[2]);
	printf("%d",l->content[3]);
	printf("%d",l->content[4]);
	printf("%d",l->content[5]);
	
}
