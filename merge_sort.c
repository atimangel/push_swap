#include "push_swap.h"

int	get_num(t_list **list)
{
	return (*(int *)(*list)->content);
}

static void	devide(t_list **a, t_list **b, int time)
{
	while (time--)
	{
		pb(a, b);
		rb(b);
	}
}

static void	compare(t_list **a, t_list **b, int len_a, int len_b)
{
	while (len_a + len_b)
	{
		if (!len_a && len_b)
		{
			pa(a, b);
			ra(a);
			len_b--;
		}
		else if (!len_b && len_a)
		{
			ra(a);
			len_a--;
		}
		else if (len_a && len_b && get_num(a) < get_num(b))
		{
			ra(a);
			len_a--;
		}
		else if (len_a && len_b && get_num(b) < get_num(a))
		{
			pa(a, b);
			ra(a);
			len_b--;
		}
	}
}

static void compare_last(t_list **a, t_list **b, int len_a, int len_b)
{
	devide(a, b, len_b);
	compare(a, b, len_a, len_b);
}

void	msort(t_list **a, t_list **b, int len, int level)
{
	int	sorted;
	int	should_sort;
	int	last;

	if (len <= 1)
		return ;
	sorted = 0;
	should_sort = len / level;
	last = len % level;
	devide(a, b, should_sort * level / 2);
	while (sorted++ < len / level)
		compare(a, b, level / 2, level / 2);
	if ((last = len % level))
		compare_last(a, b, level, last);
	if (level + last == len)
		return ;
	else
		msort(a, b, len, 2 * level);
}
