/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:56 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/16 15:09:53 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->vars->mutex);
	if (philo->vars->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->vars->mutex);
		return ;
	}
	printf("%d %d %s\n", get_time() - philo->vars->start, philo->id, message);
	pthread_mutex_unlock(&philo->vars->mutex);
}

int	kill_philo(t_philo *philo)
{
	if (get_time() - philo->vars->start > philo->soon_dead)
	{
		pthread_mutex_lock(&philo->vars->dead);
		printf("%d %d died\n", get_time() - philo->vars->start, philo->id);
		philo->vars->is_dead = 1;
		pthread_mutex_unlock(&philo->vars->dead);
		pthread_mutex_unlock(&philo->vars->mutex);
		return (1);
	}
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->vars->is_dead == 0)
	{
		// printf("%d %d is alive\n", get_time() - p->vars->start, p->id);
		if (is_dead(p))
			return (0) ;
		take_forks(p);
		if (is_dead(p))
		{
			pthread_mutex_unlock(p->left_fork);
			pthread_mutex_unlock(p->right_fork);
			return (0) ;
		}
		eat(p);
		if (is_dead(p))
			return (0) ;
		sleeping(p);
		if (is_dead(p))
			return (0) ;
		think(p);
		usleep(200);
	}
	return (NULL);
}

void	join_thread(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_philo)
	{
		pthread_join(vars->philo[i].id_thread, NULL);
		i++;
	}
}

void	free_philo(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_philo)
	{
		pthread_mutex_destroy(&vars->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&vars->dead);
	pthread_mutex_destroy(&vars->mutex);
	free(vars->forks);
	free(vars->philo);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (check_args(argv))
	{
		printf("Error: wrong arguments\n");
		return (1);
	}
	if (pthread_mutex_init(&vars.mutex, NULL))
	{
		printf("Error: pthread_mutex_init failed\n");
		return (1);
	}
	if (init_vars(&vars, argv))
		return (1);
	if (init_threads(&vars))
	{
		free_philo(&vars);
		return (1);
	}
	join_thread(&vars);
	free_philo(&vars);
	return (0);
}
