#include "push_swap.h"

void rotate(t_list **list)
{
	t_list *first;

	if (!list)
		return ;
	if (!*list)
		return ;
	if (ft_lstsize(*list) < 2)
		return ;
	first = *list;
	ft_lstlast(*list)->next = *list;
	*list = (*list)->next;
	first->next = NULL;
}

void ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
