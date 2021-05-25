//#include "push_swap.h"
#include <stdio.h>
#include "libft_bonus.h"
#include "libft.h"

int	main(int arg_c, char **arg_v)
{
	t_list **a;

	a = (t_list **)malloc(sizeof(t_list *));
	if (!a)
	{
		ft_putstr_fd("error\n", 2);
		return(0);
	}
	ft_lstadd_back(a, ft_lstnew(ft_atoi_ptr(arg_v[1])));
	if (!(*a)->content)
	{
		ft_putstr_fd("error\n", 2);
		ft_lstclear(a, free);
		return(0);
	}
	printf("%p %p %d\n", a, *a, *(int *)(*a)->content);
	ft_lstclear(a, free);
	return (0);
}
