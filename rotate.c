/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:38:39 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:18:45 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node_h *list)
{
	if (!list)
		return ;
	if (list->len <= 1)
		return ;
	list->tail = list->head;
	list->head = list->tail->next;
}

void	ra(t_node_h *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node_h *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node_h *a, t_node_h *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
