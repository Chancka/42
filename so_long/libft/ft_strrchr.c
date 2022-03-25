/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:54:17 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 18:16:41 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*stemp;
	int		i;

	stemp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			stemp = (char *)(s + i);
		i++;
	}	
	if (s[i] == (char)c)
		stemp = (char *)(s + i);
	return (stemp);
}
