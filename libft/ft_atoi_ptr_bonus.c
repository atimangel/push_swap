/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:44:57 by snpark            #+#    #+#             */
/*   Updated: 2021/05/31 17:04:03 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "libft.h"

static	int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	int	ft_ispm(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (0);
}

static int	c_to_n(int i, const char *string, long int *bowl, int negative)
{
	while (ft_isdigit(string[i]))
	{
		*bowl *= 10;
		*bowl += string[i] - '0';
		if (negative != -1 && *bowl > 2147483647)
			return (-1);
		if (negative == -1 && *bowl > 2147483648)
			return (-1);
		i++;
	}
	return (i);
}

int			*ft_atoi_ptr(const char *string)
{
	int			i;
	int			*number;
	long int	bowl;
	int			negative;

	i = 0;
	number = (int *)malloc(sizeof(int));
	if (!number)
		return (number);
	bowl = 0;
	while (ft_isspace(string[i]))
		i++;
	if ((negative = ft_ispm(string[i])) != 0)
		i++;
	i = c_to_n(i, string, &bowl, negative);
	if (i == -1 || string[i])
	{
		free(number);
		return (NULL);
	}
	if (negative == -1)
		bowl *= -1;
	*number = (int)bowl;
	return (number);
}

/*
**ASCII to INTEGER return pointer
**Convert ther string pointed to,
**by the argument str to an integer.
**[whitespace][sign][digits]
**str - String to be converted.
**whitespace = isspace()
**sign = + or - one sign
*/
