/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:41 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 16:24:38 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle)
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len && needle[j] && haystack[ i + j])
			{
				j++;
				if (j == len)
				{
					return ((char *)haystack + i);
				}
			}
			i++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
