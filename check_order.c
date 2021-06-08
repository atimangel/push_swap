#include "push_swap.h"

int	check_order(t_node_handler a)
{
	int	i;
	t_node	*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index + 1 == head->next->index)
		head = head->next;
	return (i);
}

int	check_ascending(t_node_handler a)
{
	int	i;
	t_node	*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index < head->next->index)
		head = head->next;
	return (i);

}

int	check_descending(t_node_handler a)
{
	int	i;
	t_node	*head;

	i = 0;
	head = a.head;
	while (i++ < a.len && head->index > head->next->index)
		head = head->next;
	return (i);

}
