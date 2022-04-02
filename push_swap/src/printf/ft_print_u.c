/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:34:09 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 10:57:20 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = nbr;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	if (nb >= 10)
		ft_putnbr_u(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_print_u(va_list args)
{
	return (ft_putnbr_u(va_arg(args, int)));
}
