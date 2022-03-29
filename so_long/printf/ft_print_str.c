/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 03:54:04 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 10:58:14 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i = i + ft_putchar(str[i]);
	return (i);
}

int	ft_print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	else
		return (ft_putstr(str));
}
