/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:27:52 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 15:18:45 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (i < size && dest[i])
		i++;
	if (i == size)
		return (i + (unsigned int)ft_strlen((char *)src));
	j = 0;
	k = i;
	while (src[j])
	{
		if (j < size - i - 1)
		{
			dest[k] = src[j];
			k++;
		}
		j++;
	}
	dest[k] = '\0';
	return (i + j);
}
