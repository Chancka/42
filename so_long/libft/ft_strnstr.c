/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:29:41 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/26 10:13:17 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	i = 0;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && i + j < len
			&& needle[j] && hay[i + j])
			j++;
		if (j == ft_strlen(needle))
			return (hay + i);
		i++;
	}
	return (0);
}
