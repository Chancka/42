/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:34:58 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 11:12:35 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *p, int v, size_t len)
{
	unsigned char	*i;

	i = p;
	while (len--)
		*i++ = (unsigned char)v;
	return (p);
}
