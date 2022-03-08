/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:39:32 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/08 13:40:33 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long int	ft_ternaire(long int boo, long int rtrue, long int rfalse)
{
	if (boo)
		return (rtrue);
	else
		return (rfalse);
}

char	*ft_itoa(int n)
{
	char			*dest;
	size_t			len;
	long			nb;

	nb = n;
	len = ft_ternaire(n > 0, 0, 1);
	nb = ft_ternaire(nb > 0, nb, -nb);
	while (n)
		n = ft_ternaire(len++, n / 10, n / 10);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	dest[len--] = '\0';
	while (nb > 0)
	{
		dest[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (len == 0 && dest[1] == '\0')
		dest[len] = '0';
	else if (len == 0 && dest[1] != '\0')
		dest[len] = '-';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] && str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}