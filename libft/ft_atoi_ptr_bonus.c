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

int			*ft_atoi_ptr(const char *string)
{
	int			i;
	int			*number;
	long int		bowl;
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
	while (ft_isdigit(string[i]))
	{
		bowl *= 10;
		bowl += string[i] - '0';
		if (negative != -1 && bowl > 2147483647)
			return (NULL);
		if (negative == -1 && bowl > 2147483648)
			return (NULL);
		i++;
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
