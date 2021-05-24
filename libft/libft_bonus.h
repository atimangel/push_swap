/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.ke>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:45:14 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 14:58:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_BONUS_H
# define _LIBFT_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

int		get_next_line(int fd, char **line);
int		*ft_atoi_ptr(const char *string);
#endif
