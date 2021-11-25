/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:48:59 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/25 18:17:14 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strchr(const char *s, int c)
{
	char	*stemp;
	int		i;

	stemp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (stemp = (char *)(s + i));
		i++;
	}	
	if (s[i] == (char)c)
		return (stemp = (char *)(s + i));
	return (0);
}
