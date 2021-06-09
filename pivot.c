/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:04:08 by snpark            #+#    #+#             */
/*   Updated: 2021/06/09 15:13:59 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_pivot(t_pivot *pivot, unsigned int max, unsigned int min)
{
	pivot->max = max;
	pivot->min = min;
	pivot->len = max - min + 1;
	pivot->pivot = (pivot->len / 2) + min - ((pivot->len + 1) % 2);
}
