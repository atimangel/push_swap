/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/05/31 17:07:04 by snpark           ###   ########.fr       */
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
	t_list	*a;
	t_list	*b;
	int		i;

	if (arg_c == 1)
		return (0);
	printf("1 %s\n", arg_v[1]);
	a = make_list(arg_c, arg_v);
	b = NULL;
	if (!a)
		return (0);
	msort(&a, &b, arg_c - 1, 2);
	return (0);
}
