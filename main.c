/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/06/14 10:56:10 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_b_list(t_node_h *b)
{
	b->head = 0;
	b->tail = 0;
	b->len = 0;
}

int			main(int arg_c, char **arg_v)
{
	t_node_h		a;
	t_node_h		b;
	t_pivot			a_range;
	t_pivot			b_range;

	if (arg_c == 1)
		return (0);
	if (!make_list(arg_c, arg_v, &a))
		return (0);
	set_b_list(&b);
	set_pivot(&a_range, a.len - 1, 0);
	set_pivot(&b_range, 0, 0);
	b_range.len = 0;
	if (a.len == check_order(a))
		return (0);
	if (a.len == 2)
		sa(&a);
	if (a.len == 3)
		sort_3_a(&a);
	if (a.len >= 4)
		quick_sort(&a, &b, a_range, b_range);
	ft_nodeclear(&a);
	ft_nodeclear(&b);
	return (0);
}
