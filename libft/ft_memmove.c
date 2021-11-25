/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:36:19 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 11:12:21 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int					i;
	unsigned char		*dtemp;
	unsigned const char	*stemp;

	dtemp = dest;
	stemp = src;
	i = 0;
	while (len--)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	dest = dtemp;
	return (dest);
}

