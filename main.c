/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/06/08 19:09:23 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	checkcontent(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putchar_fd('\n', 1);
}

int		main(int arg_c, char **arg_v)
{
	t_node_handler	a;
	t_node_handler	b;
	t_pivot			a_range;
	t_pivot			b_range;

	if (arg_c == 1)
		return (0);
	if (!make_list(arg_c, arg_v, &a))
		return (0);
	print_list(a);
	b.head = 0;
	b.tail = 0;
	b.len = 0;
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
	putnode(a, 'a');
	putnode(b, 'b');
	return (0);
}
