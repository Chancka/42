/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:21:17 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/23 14:56:22 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(unsigned int c)
{
	if (c >= 32 && c <= 127)
		return (1);
	else
		return (0);
}
