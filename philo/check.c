/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:29:19 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/20 12:51:43 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_int(char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 12)
			return (0);
		nb = ft_atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_data(char **argv)
{
	if (ft_atoi(argv[1]) > 200)
		return (0);
	if (ft_atoi(argv[2]) < 60)
		return (0);
	if (ft_atoi(argv[3]) < 60)
		return (0);
	if (ft_atoi(argv[4]) < 60)
		return (0);
	return (1);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (check_int(argv) == 0)
		return (1);
	if (check_data(argv) == 0)
		return (2);
	return (0);
}
