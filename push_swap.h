/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:39:30 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 17:39:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libft_bonus.h"
# define ERROR "Error\n"
typedef struct s_node t_node ;

typedef struct s_node {
	int		index;
	int		num;
	t_node	*next;
	t_node	*back;
}				t_node;

typedef	struct	s_node_handler {
	t_node	*head;
	t_node	*tail;
	int		len;
}				t_node_handler;

/*
**UTILS
*/
void	checkcontent(void *num);
int		make_list(int arg_c, char **arg_v, t_node_handler *dest);
void	putnode(t_node_handler handle, char c);
/*
**NODE
**/
void	ft_nodeclear(t_node_handler *handle);
void	ft_nodeadd_back(t_node_handler *handle, t_node *node);
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
