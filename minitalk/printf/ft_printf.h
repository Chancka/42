/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:59:51 by cboudrin          #+#    #+#             */
/*   Updated: 2022/01/07 14:26:07 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define CONVERSION "cspdiuxX"

typedef int	(*t_ptrfonction)();

int	ft_putstr(char *str);

int	ft_putchar_print(va_list args);

int	ft_print_hexa(va_list args);

int	ft_print_hexa_maj(va_list args);

int	ft_putnbr_base(long unsigned int nbr, char *base);

int	ft_print_u(va_list args);

int	ft_putchar(char c);

int	ft_print_str(va_list args);

int	ft_print_nbr(va_list args);

int	ft_print_ptr(va_list args);

int	ft_printf(const char *format, ...);

#endif
