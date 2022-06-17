/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:09:00 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/16 15:05:38 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_philo)
	{
		if (pthread_mutex_init(&vars->forks[i], NULL) != 0)
			return (1);
		vars->philo[i].left_fork = &vars->forks[i];
		vars->philo[i].right_fork = &vars->forks[(i + 1) % vars->nb_philo];
		i++;
	}
	if (pthread_mutex_init(&vars->mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&vars->dead, NULL) != 0)
		return (1);
	return (0);
}

static int	init_philo(t_vars *vars)
{
	int		i;

	i = 0;
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->nb_philo);
	if (!vars->forks)
		return (1);
	vars->philo = malloc(sizeof(t_philo) * (vars->nb_philo));
	if (!vars->philo)
		return (1);
	while (i < vars->nb_philo)
	{
		vars->philo[i].id = i + 1;
		vars->philo[i].is_eating = 0;
		vars->philo[i].is_sleeping = 0;
		vars->philo[i].last_eat = 0;
		vars->philo[i].count = 0;
		vars->philo[i].soon_dead = vars->ti_die;
		i++;
	}
	if (init_mutex(vars))
		return (1);
	i = 0;
	while (i < vars->nb_philo)
	{
		vars->philo[i].vars = vars;
		i++;
	}
	return (0);
}

int	init_vars(t_vars *vars, char **argv)
{
	if (argv[5] == NULL)
		vars->amount_loop = -1;
	else
		vars->amount_loop = ft_atoi(argv[5]);
	vars->nb_philo = ft_atoi(argv[1]);
	vars->ti_die = ft_atoi(argv[2]);
	vars->ti_eat = ft_atoi(argv[3]);
	vars->ti_sleep = ft_atoi(argv[4]);
	vars->is_dead = 0;
	vars->start = get_time();
	if (init_philo(vars))
	{
		free(vars->forks);
		return (1);
	}
	return (0);
}

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

int	init_threads(t_vars *vars)
{
	int		i;
	void	*philo;

	i = 0;
	vars->start = get_time();
	while (i < vars->nb_philo)
	{
		philo = (void *)(&vars->philo[i]);
		if (i % 2 == 0 && (pthread_create(&vars->philo[i].id_thread, NULL, &routine, philo)) != 0)
		{
			printf("Error: pthread_create failed\n");
			return (1);
		}
		i++;
	}
	i = 0;
	usleep(10);
	while (i < vars->nb_philo)
	{
		philo = (void *)(&vars->philo[i]);
		if (i % 2 == 1 && (pthread_create(&vars->philo[i].id_thread, NULL, &routine, philo)) != 0)
		{
			printf("Error: pthread_create failed\n");
			return (1);
		}
		i++;
	}	
	monitor(vars, 0, 0);
	return (0);
}
