/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:45:06 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/20 12:46:47 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *var_v, int i, int nb_philo_count)
{
	t_vars	*vars;

	vars = (t_vars *)var_v;
	while (1)
	{
		i = -1;
		while (++i < vars->nb_philo)
		{
			pthread_mutex_lock(&vars->mutex);
			if (vars->philo[i].count == vars->amount_loop)
			{
				nb_philo_count++;
				vars->philo[i].count = -1;
				if (nb_philo_count == vars->nb_philo)
				{
					vars->is_dead = 1;
					return (pthread_mutex_unlock(&vars->mutex), NULL);
				}
			}
			if (kill_philo(&vars->philo[i]))
				return (NULL);
			pthread_mutex_unlock(&vars->mutex);
		}
		usleep(200);
	}
}

int	print_and_ret(char *message)
{
	printf("%s\n", message);
	return (1);
}

int	init_threads(t_vars *vars)
{
	int		i;
	void	*philo;

	i = -1;
	vars->start = get_time();
	while (++i < vars->nb_philo)
	{
		philo = (void *)(&vars->philo[i]);
		if (i % 2 == 0 && (pthread_create(&vars->philo[i].id_thread,
					NULL, &routine, philo)) != 0)
			return (print_and_ret("Error: pthread_create failed\n"));
	}
	i = -1;
	usleep(10);
	while (++i < vars->nb_philo)
	{
		philo = (void *)(&vars->philo[i]);
		if (i % 2 == 1 && (pthread_create(&vars->philo[i].id_thread,
					NULL, &routine, philo)) != 0)
			return (print_and_ret("Error: pthread_create failed\n"));
	}	
	monitor(vars, 0, 0);
	return (0);
}
