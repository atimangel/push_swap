#include "push_swap.h"

void	swap(t_list **list)
{
	t_list *second;
	
	if (ft_lstsize(*list) < 2)
		return ;
	second = (*list)->next;
	(*list)->next = second->next;
	second->next = (*list);
	list = &second;
}

void	sa(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);	
}
