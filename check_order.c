/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:02:18 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:26:14 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	check_order(t_node_h a)
{
	unsigned int	i;
	t_node			*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index + 1 == head->next->index)
		head = head->next;
	return (i);
}

int				check_reverse_order(t_node_h a)
{
	unsigned int		i;
	t_node				*tail;

	i = 0;
	tail = a.tail;
	while (i++ < a.len && tail->index - 1 == tail->back->index)
		tail = tail->back;
	return (i);
}

int				pivot_order(t_node_h a, unsigned int pivot)
{
	unsigned int	reverse_count;
	unsigned int	order_count;
	t_node			*head;
	t_node			*tail;

	head = a.head->next;
	tail = a.head->back;
	reverse_count = 0;
	while (reverse_count++ < a.len && head->index > pivot)
		head = head->next;
	order_count = 0;
	while (order_count++ < a.len && tail->index > pivot)
		tail = tail->back;
	reverse_count = (a.len - reverse_count) * 2 + 1 + 2;
	order_count = a.len - order_count + 1 + 2;
	if (head->index == pivot || head->next->index == pivot)
		reverse_count -= 2;
	if (tail->index == pivot || tail->back->index == pivot)
		order_count -= 2;
	if (reverse_count < order_count)
		return (-1);
	else
		return (1);
}

int				check_ascending(t_node_h a)
{
	unsigned int	i;
	t_node			*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index < head->next->index)
		head = head->next;
	return (i);
}

int				check_descending(t_node_h a)
{
	unsigned int	i;
	t_node			*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index > head->next->index)
		head = head->next;
	return (i);
}
