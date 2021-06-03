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

void	push(t_node_hadler *dest, t_node_handler *src)
{
	if (src->len == 0)
		return ;
	dest->tail->next = src->head;
	dest->head->back = src->head;
	dest->head = src->head;
	dest->len++;
	src->len--;
	if (src->len == 0)
	{
		src->head = 0;
		src->tail = 0;
	}
	else (src->len <= 2)
	{
		src->head = src->head->next;
		src->head->next = src->tail;
		src->head->back = src->head;
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
