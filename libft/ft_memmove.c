/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:36:19 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 10:41:14 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int		i;
	char	*dtemp;
	char	*stemp;

	dtemp = (char *)dest;
	stemp = (char *)src;
	i = 0;
	if (stemp < dtemp)
	{
		while (len--)
			dtemp[len] = stemp[len];
	}
	else
		ft_memcpy(dest, src, len);
	return ((void *)dest);
}
