/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:34 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/07 16:49:04 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	trad_char(int num)
{
	static int	i;
	static char	byte;

	if (num == SIGUSR2)
	{
		// write(1, "1", 1);
		(byte |= (0x80 >> i));
		i++;
	}
	else
	{
		i++;
		// write(1, "0", 1);
	}
	if (i == 8)
	{
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	ret;

	(void)argv;
	pid = getpid();
	ret.sa_handler = trad_char;
	if (argc == 1)
	{
		ft_printf("PID : %i\n", pid);
		while (1)
		{
			sigaction(SIGUSR2, &ret, 0);
			sigaction(SIGUSR1, &ret, 0);
			pause();
		}
	}
	exit(EXIT_FAILURE);
}