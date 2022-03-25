/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:26 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 11:12:05 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	int		i;
	char	*dtemp;
	char	*stemp;

	dtemp = (char *)dest;
	stemp = (char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (len--)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	dest = dtemp;
	return (dest);
}
