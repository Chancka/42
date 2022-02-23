/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:36:19 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/22 13:05:39 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dtemp;
	char	*stemp;

	dtemp = (char *)dest;
	stemp = (char *)src;
	if (stemp < dtemp)
	{
		while (len--)
			dtemp[len] = stemp[len];
	}
	else
		ft_memcpy(dest, src, len);
	return ((void *)dest);
}
