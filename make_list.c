/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:19:49 by snpark            #+#    #+#             */
/*   Updated: 2021/06/10 14:08:52 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		preprocess(t_node_h *handle, t_node *node)
{
	t_node	*reader;

	reader = handle->head;
	while (reader != handle->tail)
	{
		if (node->num == reader->num)
		{
			ft_nodeclear(handle);
			ft_putstr_fd(ERROR, 2);
			return (0);
		}
		else if (node->num < reader->num)
			reader->index++;
		else if (node->num > reader->num && node->index <= reader->index)
			node->index = reader->index + 1;
		reader = reader->next;
	}
	return (1);
}

static t_node	*make_node(t_node_h *handle)
{
	t_node *node;

	node = 0;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		ft_nodeclear(handle);
		ft_putstr_fd(ERROR, 2);
		return (0);
	}
	node->index = 0;
	return (node);
}

static int		iserror(char *str, t_node *node, t_node_h *handle, int *i)
{
	if (!str || (*str && ft_ispm(*str) == -2 && !ft_isspace(*str)))
	{
		free(node);
		ft_nodeclear(handle);
		ft_putstr_fd(ERROR, 2);
		return (0);
	}
	else if (!*str)
		(*i)++;
	return (1);
}

int				make_list(int arg_c, char **arg_v, t_node_h *dest)
{
	int				i;
	t_node			*node;

	i = 1;
	dest->head = NULL;
	dest->len = 0;
	while (i < arg_c)
	{
		if (!(node = make_node(dest)))
			return (0);
		node->num = ft_atoi_ptr(&arg_v[i]);
		if (!iserror(arg_v[i], node, dest, &i))
			return (0);
		ft_nodeadd_back(dest, node);
		if (!preprocess(dest, node))
			return (0);
	}
	return (1);
}
