/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:52 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 10:56:21 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
}

int	ft_print_hexa_maj(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
}
