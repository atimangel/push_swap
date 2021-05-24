//#include "push_swap.h"
#include <stdio.h>
#include "libft_bonus.h"
#include "libft.h"

int	main(int arg_c, char **arg_v)
{
	t_list *a;

	a = ft_lstnew(ft_atoi_ptr(arg_v[1]));
	if (!a->content)
	{
		ft_putstr_fd("error\n", 2);
		return(0);
	}
	printf("%d\n", *(int *)a->content);
	ft_lstdelone(a, free);	
	return (0);
}
