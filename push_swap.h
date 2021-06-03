/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:39:30 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 17:44:06 by snpark           ###   ########.fr       */
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
void	swap(t_node_handler *swap);
void	sa(t_node_handler *a);
void	sb(t_node_handler *b);
void	ss(t_node_handler *a, t_node_handler *b);
/*
**PUSH
*/
void	push(t_node_handler *dest, t_node_handler *src);
void	pa(t_node_handler *a, t_node_handler *b);
void	pb(t_node_handler *a, t_node_handler *b);
/*
**ROTATE
*/
void	rotate(t_node_handler *list);
void	ra(t_node_handler *a);
void	rb(t_node_handler *b);
void	rr(t_node_handler *a, t_node_handler *b);
/*
**REVERSE ROTATE
*/
void	reverse_rotate(t_node_handler *list);
void	rra(t_node_handler *a);
void	rrb(t_node_handler *b);
void	rrr(t_node_handler *a, t_node_handler *b);
/*
** Merge Sort
*/
void	msort(t_node_handler *a, t_node_handler *b, int len, int level);
#endif
