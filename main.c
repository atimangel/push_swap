#include "push_swap.h"
#include <stdio.h>

t_list *make_list(int arg_c, char **arg_v)
{
	t_list	*a;
	t_list	*tmp;
	int	i;
	int	num;
	int	*integer;

	i = 1;
	a = NULL;
	while (i < arg_c)
	{
		integer = ft_atoi_ptr(arg_v[i++]);
		if (!integer)
		{
			ft_lstclear(&a, free);
			ft_putstr_fd("error\n", 2);
			return (0);
		}
		tmp = ft_lstnew(integer);
		if (!tmp)
		{
			free(integer);
			ft_lstclear(&a, free);
			ft_putstr_fd("error\n", 2);
			return (0);
		}	
		ft_lstadd_back(&a, tmp);
		tmp = a;
		while (tmp)
		{
			if (*integer == *(int *)tmp->content && integer != (int *)tmp->content)
			{
				ft_lstclear(&a, free);
				ft_putstr_fd("error\n", 2);
				return (0);
			}
			tmp = tmp->next;
		}
	}
	return (a);
}

void	checkcontent(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int arg_c, char **arg_v)
{
	t_list *a;
	t_list *b;
	int	i;

	if (arg_c == 1)
		return (0);
	a = make_list(arg_c, arg_v);
	b = NULL;
	if (!a)
		return(0);
	ft_lstiter(a, checkcontent);
	msort(&a, &b, arg_c - 1, 2);
	ft_lstiter(a, checkcontent);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
