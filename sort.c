#include "push_swap.h"

void	sort_2_a(t_node_handler *a)
{
	if (check_ascending(*a) == 1)
		sa(a);
}

void	sort_3_a(t_node_handler *a)
{
	int	index[3];

	if (a->len != 3)
		return ;
	index[0] = a->head->index;
	index[1] = a->head->next->index;
	index[2] = a->head->next->next->index;
	if (check_ascending(*a) == 2 && index[0] < index[2])
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (check_ascending(*a) == 2&& index[2] < index[1])
		rra(a);
	else if(check_descending(*a) == 3)
	{
		sa(a);
		rra(a);
	}
	else if (index[0] < index[2])
		sa(a);
	else if (index[0] > index[2])
		ra(a);
}
// sort_3
// sort_5
/*
void	sort_5_a(t_node_handler *a, t_node_handler *b)
{
	int	ascending;
	int	index[5];
	t_node	head;
	int	i;

	if (a->len < 5)
		return ;
	i = 0;
	head = a->head;
	while (i < 5)
	{
		index[i++] = head->index;
		head = head->next;
	}
	if ((ascending = check_ascending(*a)) >= 5)
		return;
	if (ascending == 4 && index[4] < index[1])
		
}*/
