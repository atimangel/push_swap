/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:39:30 by snpark            #+#    #+#             */
/*   Updated: 2021/06/10 10:44:30 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libft_bonus.h"
# define ERROR "Error\n"

typedef struct	s_node
{
	unsigned int	index;
	int				num;
	struct s_node	*next;
	struct s_node	*back;
}				t_node;

typedef	struct	s_node_h
{
	t_node			*head;
	t_node			*tail;
	unsigned int	len;
}				t_node_h;

typedef struct	s_pivot
{
	unsigned int	max;
	unsigned int	min;
	unsigned int	pivot;
	unsigned int	len;
}				t_pivot;
/*
**UTILS
*/
unsigned int	check_order(t_node_h a);
int				check_ascending(t_node_h a);
int				check_descending(t_node_h a);
int				check_reverse_order(t_node_h a);
int				pivot_order(t_node_h a, unsigned int pivot);
void			checkcontent(void *num);
int				make_list(int arg_c, char **arg_v, t_node_h *dest);
void			putnode(t_node_h handle, char c);
void			set_pivot(t_pivot *pivot, unsigned int max, unsigned int min);

/*
**NODE
*/
void			ft_nodeclear(t_node_h *handle);
void			ft_nodeadd_back(t_node_h *handle, t_node *node);
/*
**SWAP
*/
void			swap(t_node_h *swap);
void			sa(t_node_h *a);
void			sb(t_node_h *b);
void			ss(t_node_h *a, t_node_h *b);
/*
**PUSH
*/
void			push(t_node_h *dest, t_node_h *src);
void			pa(t_node_h *a, t_node_h *b);
void			pb(t_node_h *a, t_node_h *b);
/*
**ROTATE
*/
void			rotate(t_node_h *list);
void			ra(t_node_h *a);
void			rb(t_node_h *b);
void			rr(t_node_h *a, t_node_h *b);
/*
**REVERSE ROTATE
*/
void			reverse_rotate(t_node_h *list);
void			rra(t_node_h *a);
void			rrb(t_node_h *b);
void			rrr(t_node_h *a, t_node_h *b);
/*
** Quick Sort
*/
void			sort_3_a(t_node_h *a);
void			quick_sort(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r);
void			qsort_a_to_b
(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r);
void			qsort_b_to_a
(t_node_h *a, t_node_h *b, t_pivot a_r, t_pivot b_r);
#endif
