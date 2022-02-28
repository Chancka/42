/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:27:52 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/29 13:26:15 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < size && dest[i])
		i++;
	if (i == size)
		return (i + ft_strlen((char *)src));
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
