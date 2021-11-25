/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:48:59 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 16:02:43 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*stemp;
	int	i;

	stemp = (char *) s;
	i = 0;
	while (stemp[i])
	{
		if (stemp[i] == c)
			return (s[i]);
	}
	return (NULL);

}
