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
	while (i < arg_c)
	{
		if (i == 1)
		{
			integer = ft_atoi_ptr(arg_v[i++]);
			if (!integer)
			{
				ft_putstr_fd("error\n", 2);
				return (0);
			}
			a = ft_lstnew(integer);
			if (!a)
			{
				ft_putstr_fd("error\n", 2);
				return (0);
			}
		}
		else
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
			num = *(int *)ft_lstlast(a)->content;
			while (!tmp)
			{
				if (num == *(int *)tmp->content && tmp != ft_lstlast(a))
				{
					ft_putstr_fd("error\n", 2);
					return (0);
				}
				tmp = tmp->next;
			}
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
	i = 1;
	a = make_list(arg_c, arg_v);
	b = NULL;
	ft_lstiter(a, checkcontent);
	sa(&a);
	pb(&a, &b);
	printf("a\n");
	ft_lstiter(a, checkcontent);
	printf("b\n");
	ft_lstiter(b, checkcontent);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
