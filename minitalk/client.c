/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:57 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/07 16:50:44 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
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


void	send_char(int pid, unsigned char byte)
{
	int	bit;

	bit = 0;
	if (!byte)
		return ;
	while (bit < 8)
	{
		if (byte & 128)
		{
			kill(pid, SIGUSR2);
			// printf("1");
		}
		else
		{
			kill(pid, SIGUSR1);
			// printf("0");
		}
		byte = byte << 1;
		bit++;
		usleep(3000);
	}
}

void	main_handler(int pid, char *message)
{
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac > 1 && ac <= 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 0)
		{
			ft_printf("Invalid PID");
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_printf("Le message s'envoie\n");
			main_handler(pid, av[2]);
			usleep(1000);
			ft_printf("Le message est parti\n");
			exit(EXIT_SUCCESS);
		}
	}
	ft_printf("Pas bon les arguments\n");
}