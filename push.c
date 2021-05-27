#include "push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list *first_src;

	if (ft_lstsize(*src) == 0)
		return ;
	first_src = *src;
	*src = first_src->next;
	first_src->next = *dest;
	*dest = first_src;

}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}