#include "push_swap.h"

void	ft_nodeadd_back(t_node_handler *handle, t_node *node)
{
	if (!handle)
		return ;
	if (!handle->len)
	{
		handle->head = node;
		handle->tail = node;
		node->next = node;
		node->back = node;
		handle->len = 1;
		return ;
	}
	handle->len++;
	handle->tail->next = node;
	node->back = handle->tail;
	handle->tail = node;
	handle->head->back = node;
	node->next = handle->head;
	return ;
}

void	ft_nodeclear(t_node_handler *handle)
{
	t_node *tmp;

	while (handle->len--)
	{
		tmp = handle->head->next;
		free(handle->head);
		handle->head = tmp;
	}
	handle->head = 0;
	handle->tail = 0;
}

void	putnode(t_node_handler handle, char c)
{
	ft_putchar_fd(c, 1);
	ft_putchar_fd(' ', 1);
	while (handle.len--)
	{
		ft_putnbr_fd(handle.head->num, 1);
		ft_putchar_fd(' ', 1);
		handle.head = handle.head->next;
	}
	ft_putchar_fd('\n', 1);
}
