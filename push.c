/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:42:08 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 18:25:05 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node_handler *dest, t_node_handler *src)
{
	t_node *src_head;

	if ((!dest || !src) || (src->len == 0))
		return ;
	src_head = src->head;
	if (--src->len == 0)
	{
		src->head = 0;
		src->tail = 0;
	}
	else
	{
		src->head = src->head->next;
		src->tail->next = src->head;
		src->head->back = src->tail;
	}
	dest->head = src_head;
	if (dest->len++ == 0)
	{
		src_head->next = src_head;
		src_head->back = src_head;
		dest->tail = src_head;
	}
	else
	{
		dest->head->next = dest->tail->next;
		dest->head->next->back = dest->head;
		dest->head->back = dest->tail;
		dest->tail->next = dest->head;
	}
}

void	pa(t_node_handler *a, t_node_handler *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node_handler *a, t_node_handler *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
