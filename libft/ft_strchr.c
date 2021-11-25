/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:48:59 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 10:55:14 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*stemp;
	int		i;

	stemp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (stemp = (char *)(s + i));
		i++;
	}	
	if (s[i] == c)
		return (stemp = (char *)(s + i));
	return (0);
}
