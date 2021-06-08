/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 17:11:55 by snpark           ###   ########.fr       */
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
	int		i;

	if (arg_c == 1)
		return (0);
	if (!make_list(arg_c, arg_v, &a))
		return (0);
	b.head = 0;
	b.tail = 0;
	b.len = 0;
	if (a.len == check_order(a))
		return (0);
	if (a.len == 2)
		sa(&a);
	if (a.len == 3)
		sort_3_a(&a);
	
	sa(&a);
//rder_check(a);
	//msort(&a, &b, arg_c - 1, 2);
	putnode(a, 'a');
	putnode(b, 'b');
	return (0);
}
