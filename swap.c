/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:40:29 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 17:56:53 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node_handler *handle)
{
	t_node	*tmp;

	if (handle->len < 2)
		return ;
	tmp = handle->head->next;
	handle->tail->next = tmp;
	tmp->next->back = handle->head;
	tmp->back = handle->tail;
	tmp->next = handle->head;
	handle->head->next = tmp->next;
	habdle->head->back = tmp;
	handle->head = tmp;
}

void	sa(t_node_handler *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node_handler *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node_handler *a, t_node_handler *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
