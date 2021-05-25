//#include "push_swap.h"
#include <stdio.h>
#include "libft_bonus.h"
#include "libft.h"

int	main(int arg_c, char **arg_v)
{
	t_list *a;
	t_list *tmp;
	int	i;
	int	*num;

	i = 1;
	while (i < arg_c)
	{
		tmp = a;
		num = ft_atoi_ptr(arg_v[i++]);
		if (!num)
		{
			ft_putstr_fd("error\n", 2);
			ft_lstclear(&a, free);
			return(0);
		}
		if (!a)
			a = ft_lstnew(num);
		else
		{
			while (!tmp)
			{
				if (*(int *)tmp->content == *num)
				{
					ft_putstr_fd("error\n", 2);
					ft_lstclear(&a, free);
					return (0);
				}
				if (!tmp->next)
				{
					tmp->next = ft_lstnew(num);
					break;
				}
				tmp = tmp->next;
			}
		}
		printf("%d\n", *num);
	}
	ft_lstclear(&a, free);
	return (0);
}
