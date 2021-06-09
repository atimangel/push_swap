/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:40:29 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:17:17 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node_h *handle)
{
	if (handle->len < 2)
		return ;
	handle->head = handle->head->next;
	if (handle->len == 2)
	{
		handle->tail = handle->head->next;
		return ;
	}
	handle->head->back->next = handle->head->next;
	handle->head->next->back = handle->head->back;
	handle->head->back->back = handle->head;
	handle->head->next = handle->head->back;
	handle->tail->next = handle->head;
	handle->head->back = handle->tail;
}

void	sa(t_node_h *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node_h *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node_h *a, t_node_h *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
