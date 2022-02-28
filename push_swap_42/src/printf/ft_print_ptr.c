/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 04:10:52 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 10:53:52 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long unsigned int nbr, char *base)
{
	int	nbr_final[100];
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (nbr == 0)
	{
		nbr_final[i] = 0;
		i++;
	}
	while (nbr)
	{
		nbr_final[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		count = count + ft_putchar(base[nbr_final[i]]);
	return (count);
}

int	ft_ptr(void *ptr)
{
	if (ptr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	else
		return (ft_putstr("0x")
			+ ft_putnbr_base((long unsigned int)ptr, "0123456789abcdef"));
}

int	ft_print_ptr(va_list args)
{
	return (ft_ptr(va_arg(args, void *)));
}
