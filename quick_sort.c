/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:04:08 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:23:35 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r)
{
	if (check_order(*a) == a->len && !b->len)
		return ;
	qsort_a_to_b(a, b, a_r, b_r);
	qsort_b_to_a(a, b, a_r, b_r);
}

static void	a_list_under_3(t_node_h *a, t_pivot *a_r)
{
	if (a_r->len == 2)
	{
		if (a->head->index - 1 == a->head->next->index)
			sa(a);
		a_r->max = a_r->min;
		a_r->len = 0;
		a_r->pivot = 0;
	}
	if (a_r->len == 3)
		a_r->pivot = a_r->max;
	if (a_r->len == 1)
		a_r->len = 0;
}

void		qsort_a_to_b(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r)
{
	unsigned int push;
	unsigned int rotate;

	a_list_under_3(a, &a_r);
	if (a_r.len == 0)
		return ;
	push = a_r.pivot - a_r.min + 1;
	rotate = 0;
	while (push)
	{
		if (a->head->index > a_r.pivot)
		{
			ra(a);
			rotate++;
		}
		else if (a->head->index <= a_r.pivot && push--)
			pb(a, b);
	}
	set_pivot(&b_r, a_r.pivot, a_r.min);
	set_pivot(&a_r, a_r.max, a_r.pivot + 1);
	while (a_r.len != a->len && rotate--)
		rra(a);
	quick_sort(a, b, a_r, b_r);
	return ;
}

static void	b_list_under_2(t_node_h *a, t_node_h *b, t_pivot *b_r)
{
	if (b_r->len == 2 && check_order(*b) >= 2)
		sb(b);
	if (b_r->len == 1)
	{
		pa(a, b);
		b_r->len = 0;
	}
}

void		qsort_b_to_a(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r)
{
	unsigned int	rotate;
	unsigned int	push;

	b_list_under_2(a, b, &b_r);
	if (b_r.len == 0)
		return ;
	push = b_r.max - b_r.pivot;
	rotate = 0;
	while (push)
	{
		if (b->head->index <= b_r.pivot)
		{
			rb(b);
			rotate++;
		}
		else if (b->head->index > b_r.pivot && push--)
			pa(a, b);
	}
	set_pivot(&a_r, b_r.max, b_r.pivot + 1);
	set_pivot(&b_r, b_r.pivot, b_r.min);
	while (b_r.len != b->len && rotate--)
		rrb(b);
	quick_sort(a, b, a_r, b_r);
	return ;
}
