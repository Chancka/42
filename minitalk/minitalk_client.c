/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:57 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/08 14:00:00 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

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
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		// write(1, &message[i], 1);
		i++;
	}
	// send_char(pid, message[i]);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac > 1 && ac <= 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Invalid PID", 11);
			exit(EXIT_FAILURE);
		}
		else
		{
			write(1, "Le message s'envoie\n", 21);
			main_handler(pid, av[2]);
			usleep(600);
			write(1, "Le message est parti\n", 22);
			exit(EXIT_SUCCESS);
		}
	}
	write(1, "Pas bon les arguments\n", 23);
}