/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:46:16 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 14:37:06 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

t_ptrfonction	dispatch(char c)
{
	int				index;
	t_ptrfonction	callback[8];

	callback[0] = ft_putchar_print;
	callback[1] = ft_print_str;
	callback[2] = ft_print_ptr;
	callback[3] = ft_print_nbr;
	callback[4] = ft_print_nbr;
	callback[5] = ft_print_u;
	callback[6] = ft_print_hexa;
	callback[7] = ft_print_hexa_maj;
	index = (strlen(CONVERSION) - strlen(strchr(CONVERSION, c)));
	return (callback[index]);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				count;
	int				i;
	t_ptrfonction	print_conv;

	i = -1;
	va_start(args, format);
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i++])
		{
			if (format[i] == '%')
				count = count + ft_putchar(format[i]);
			else
			{
				print_conv = dispatch(format[i]);
				count = count + print_conv(args);
			}
		}
		else
			count = count + ft_putchar(format[i]);
	}
	va_end(args);
	return (count);
}

// int	main()
// {
// 	ft_printf("blabla %% oui");
// }