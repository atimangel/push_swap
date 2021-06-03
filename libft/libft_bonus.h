/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.ke>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:45:14 by snpark            #+#    #+#             */
/*   Updated: 2021/06/03 14:20:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_BONUS_H
# define _LIBFT_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

int		get_next_line(int fd, char **line);
int		ft_atoi_ptr(char **origin);
int		ft_ispm(char c);
int		ft_isspace(char c);
#endif
