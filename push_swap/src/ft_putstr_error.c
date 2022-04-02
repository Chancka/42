/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:16:35 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/02 13:21:00 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_error(str[i]);
		i++;
	}
}
