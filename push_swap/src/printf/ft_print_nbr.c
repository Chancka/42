/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 00:57:39 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 10:49:16 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int nbr)
{
	long long int	nb;
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
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_print_nbr(va_list args)
{
	long long int	nb;

	nb = va_arg(args, int);
	return (ft_putnbr(nb));
}
