/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:12:26 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/23 17:23:12 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int len)
{
	int					i;
	unsigned char		*dtemp;
	unsigned const char	*stemp;

	dtemp = dest;
	stemp = src;
	i = 0;
	while (len--)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	dest = dtemp;
	return (dest);
}
