/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:09:00 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/20 12:45:19 by cboudrin         ###   ########.fr       */
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

	i = -1;
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->nb_philo);
	if (!vars->forks)
		return (1);
	vars->philo = malloc(sizeof(t_philo) * (vars->nb_philo));
	if (!vars->philo)
		return (1);
	while (++i < vars->nb_philo)
	{
		vars->philo[i].id = i + 1;
		vars->philo[i].is_eating = 0;
		vars->philo[i].is_sleeping = 0;
		vars->philo[i].last_eat = 0;
		vars->philo[i].count = 0;
		vars->philo[i].soon_dead = vars->ti_die;
	}
	if (init_mutex(vars))
		return (1);
	i = -1;
	while (++i < vars->nb_philo)
		vars->philo[i].vars = vars;
	return (0);
}

static void	*only_one(void *av)
{
	char	**argv;

	argv = (char **)av;
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(ft_atoi(argv[2]));
	printf("%d %d died\n", ft_atoi(argv[2]), 1);
	return (NULL);
}

static int	free_and_ret(t_vars *vars)
{
	free(vars->forks);
	return (1);
}

int	init_vars(t_vars *vars, char **argv)
{
	pthread_t	thread;

	if (ft_atoi(argv[1]) == 1)
	{
		if (pthread_create(&thread, NULL, &only_one, argv)
			!= 0)
			return (1);
		pthread_join(thread, NULL);
		return (1);
	}
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
		return (free_and_ret(vars));
	return (0);
}
