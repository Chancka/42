/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:21:25 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/14 12:54:27 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] && str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}

long	ft_atol(const char *str)
{
	long long	i;
	long long	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] && str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time && !is_dead(philo))
		usleep(50);
}
