/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:39:30 by snpark            #+#    #+#             */
/*   Updated: 2021/06/08 19:09:27 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libft_bonus.h"
# define ERROR "Error\n"
typedef struct s_node t_node ;

typedef struct s_node {
	unsigned int	index;
	int				num;
	t_node			*next;
	t_node			*back;
}				t_node;

typedef	struct	s_node_handler {
	t_node			*head;
	t_node			*tail;
	unsigned int	len;
}				t_node_handler;

typedef struct s_pivot {
	unsigned int	max;
	unsigned int	min;
	unsigned int	pivot;
	unsigned int	len;
}				t_pivot;

typedef struct s_ab {
	t_node_handler	a;
	t_node_handler	b;
	t_pivot			a_range;
	t_pivot			b_range;
}		t_ab;
/*
**UTILS
*/
int		check_order(t_node_handler a);
int		check_ascending(t_node_handler a);
int		check_descending(t_node_handler a);
int		check_reverse_order(t_node_handler a);
int		pivot_order(t_node_handler a, unsigned int pivot);
void	checkcontent(void *num);
int		make_list(int arg_c, char **arg_v, t_node_handler *dest);
void	putnode(t_node_handler handle, char c);
void	set_pivot(t_pivot *pivot, unsigned int max, unsigned int min);
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
void	sort_3_a(t_node_handler *a);
void	quick_sort(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range);
void	qsort_a_to_b(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range);
void	qsort_b_to_a(t_node_handler *a, t_node_handler *b, t_pivot a_range, t_pivot b_range);
void	msort(t_node_handler *a, t_node_handler *b, int len, int level);


void	print_list(t_node_handler a);
#endif
