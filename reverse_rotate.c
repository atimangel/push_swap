#include "push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list *n_minus_1;
	int	size;

	if ((size = ft_lstsize(*list)) <= 1)
		return ;
	n_minus_1 = *list;
	while (size != 2)
	{
		size--;
		n_minus_1 = n_minus_1->next;	
	}
	(n_minus_1->next)->next = *list;
	*list = n_minus_1->next;
	n_minus_1->next = 0;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
