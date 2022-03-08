/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:35:34 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/08 14:00:36 by cboudrin         ###   ########.fr       */
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

void		print_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	ret;

	(void)argv;
	ret.sa_handler = trad_char;
	if (argc == 1)
	{
		print_pid();
		sigaction(SIGUSR1, &ret, 0);
		sigaction(SIGUSR2, &ret, 0);
		while (1)
		{
			pause();
		}
	}
	exit(EXIT_FAILURE);
}