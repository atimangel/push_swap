/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:24:19 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:24:45 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_node_h *a)
{
	if (check_ascending(*a) == 1)
		sa(a);
}

void	sort_3_a(t_node_h *a)
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
	else if (check_ascending(*a) == 2 && index[2] < index[1])
		rra(a);
	else if (check_descending(*a) == 3)
	{
		sa(a);
		rra(a);
	}
	else if (index[0] < index[2])
		sa(a);
	else if (index[0] > index[2])
		ra(a);
}
