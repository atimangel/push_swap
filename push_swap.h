#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libft_bonus.h"

/*
**NODE
*/
/*
typedef struct s_node
{
	t_node *head;
	int	num;
	t_node *tail;
}		t_node;
*/
/*
for parsing
	t_node	*node_new();
	void	node_add_back();
for swap
for push
for rotate
for reverse rotate
for free
*/
void	checkcontent(void *num);
/*
**SWAP
*/
void	swap(t_list **list);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
/*
**PUSH
*/
void	push(t_list **dest, t_list **src);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
/*
**ROTATE
*/
void	rotate(t_list **list);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
/*
**REVERSE ROTATE
*/
void	reverse_rotate(t_list **list);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
/*
** Merge Sort
*/
void	msort(t_list **a, t_list **b, int len, int level);
#endif
