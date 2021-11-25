/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:52:12 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 18:38:28 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	s1temp = (unsigned char *)s1;
	s2temp = (unsigned char *)s2;
	i = 0;
	if (n == 0 || s1 == s2)
		return (0);
	while (i < n)
	{
		if (s1temp[i] != s2temp[i])
			return (s1temp[i] - s2temp[i]);
		i++;
	}
	return (0);
}
