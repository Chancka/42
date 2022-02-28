/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:13:39 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/28 19:28:05 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
