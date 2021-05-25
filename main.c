//#include "push_swap.h"
#include <stdio.h>
#include "libft_bonus.h"
#include "libft.h"

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
			printf("i = %d\n", i);
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
			printf("tmp %p end %p num %d\n", tmp, ft_lstlast(a), *(int *)tmp->content);
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

int	main(int arg_c, char **arg_v)
{
	t_list *a;
	t_list *tmp;
	int	i;
	int	*num;

	i = 1;
	a = make_list(arg_c, arg_v);
	tmp = a;
	while (tmp)
	{
		printf("tmp %p a %p num %d\n", tmp, a, *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&a, free);
	return (0);
}
