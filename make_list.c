/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/05/31 16:36:50 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_same_num(t_list **a, t_list *tmp, int *integer)
{
	while (tmp)
	{
		if (*integer == *(int *)tmp->content && integer != (int *)tmp->content)
		{
			ft_lstclear(a, free);
			ft_putstr_fd("error\n", 2);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	make_list_fail_integer(int *integer, t_list **a)
{
	if (!integer)
	{
		ft_lstclear(a, free);
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	return (1);
}

static int	make_list_fail_tmp(int *integer, t_list *tmp, t_list **a)
{
	if (!tmp)
	{
		free(integer);
		ft_lstclear(a, free);
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	return (1);
}

t_list		*make_list(int arg_c, char **arg_v)
{
	t_list	*a;
	t_list	*tmp;
	int		i;
	int		num;
	int		*integer;

	i = 1;
	a = NULL;
	while (i < arg_c)
	{
		integer = ft_atoi_ptr(arg_v[i++]);
		if (!make_list_fail_integer(integer, &a))
			return (0);
		tmp = ft_lstnew(integer);
		if (!make_list_fail_tmp(integer, tmp, &a))
			return (0);
		ft_lstadd_back(&a, tmp);
		if (!check_same_num(&a, a, integer))
			return (0);
	}
	return (a);
}
