/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:04:08 by snpark            #+#    #+#             */
/*   Updated: 2021/06/08 19:14:50 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_pivot(t_pivot *pivot, unsigned int max, unsigned int min)
{
	pivot->max = max;
	pivot->min = min;
	pivot->len = max - min + 1;
	pivot->pivot = (pivot->len / 2) + min;
}

void	quick_sort
(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range)
{
	printf("a max %d min %d pivot %d len %d\n", a_range.max, a_range.min, a_range.pivot, a_range.len);
	printf("b max %d min %d pivot %d len %d\n", b_range.max, b_range.min, b_range.pivot, b_range.len);
	if (check_order(*a) == a->len && !b->len)
			return;
	if (a->len < 4)
		return;
	if (check_order(*a) != a->len)
		qsort_a_to_b(a, b, a_range, b_range);
	if (check_order(*a) == a->len && b->len)
		qsort_b_to_a(a, b, a_range, b_range);
}

void	qsort_a_to_b
(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range)
{
	char			order;
	unsigned int	pb_cnt;
	unsigned int	ra_cnt;
	unsigned int	len;

	pb_cnt = a_range.max - a_range.pivot + (a_range.max + 1) % 2;
	ra_cnt = 0;
	order = 0;
	if (check_order(*a) != a->len)
		order = pivot_order(*a, a_range.pivot);
	while (a_range.len-- && pb_cnt && check_order(*a) != a->len)
	{
		if ((a->head->index - 1 == a->head->next->index) || (order == -1 && pb_cnt == 2 && a->head->index == a_range.pivot && a->head->next->index < a_range.pivot))
			sa(a);
		if (check_order(*a) == a->len)
			break;
		if (a->head->index > a_range.pivot && order >= 0)
		{
			ra(a);
			ra_cnt++;
		}
		else if (a->head->index > a_range.pivot && order == -1)
		{
			rra(a);
			if (a_range.len-- && pb_cnt)
				rra(a);
		}
		else if (a->head->index <= a_range.pivot && pb_cnt--)
			pb(a, b);
		if (b->len && b->head->index == a_range.pivot && pb_cnt && b->len > 1)
			rb(b);
	}
	if (!order && ra_cnt && b->len > 1 && b->tail->index == a_range.pivot)
	{
		ra_cnt--;
		rrr(a, b);
	}
	if (b->len > 1 && b->tail->index == a_range.pivot)
		rrb(b);
	while (ra_cnt-- && !order)
		rra(a);
	set_pivot(&b_range, a_range.pivot, a_range.min);
	set_pivot(&a_range, a_range.max, a_range.pivot + 1);
	if (pb_cnt)
	{
		set_pivot(&b_range, a->head->index - 1, a_range.min);
		set_pivot(&a_range, a_range.max, a->head->index);
	}
	putnode(*a, 'a');
	putnode(*b, 'b');
	quick_sort(a, b, a_range, b_range);
}

void	qsort_b_to_a
(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range)
{
	unsigned int	rb_cnt;
	unsigned int	pa_cnt;

	pa_cnt = b_range.pivot - b_range.min + 1;
	rb_cnt = 0;
	while (b_range.len-- && pa_cnt)
	{
		if (b->head->index + 1 == b->head->next->index)
			sb(b);
		if (b->head->index < b_range.pivot)
		{
			rb(b);
			rb_cnt++;
		}
		else if (b->head->index >= b_range.pivot && pa_cnt--)
			pa(a, b);
		if (a->len && a->head->index == b_range.pivot && pa_cnt && a->len > 1)
			ra(a);
	}
	if (rb_cnt && a->len > 1 && a->tail->index == b_range.pivot)
	{
		rb_cnt--;
		rrr(a, b);
	}
	if (a->len > 1 && a->tail->index == b_range.pivot)
		rra(a);
	while (rb_cnt--)
		rrb(b);
	set_pivot(&a_range, b_range.max, b_range.pivot);
	set_pivot(&b_range, b_range.pivot - 1, b_range.min);
	quick_sort(a, b, a_range, b_range);
}
