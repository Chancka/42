/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:06:13 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/14 12:54:12 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->mutex);
	if (philo->vars->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->vars->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->vars->mutex);
	return (0);
}

void	think(t_philo *philo)
{
	display_message(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	display_message(philo, "is eating");
	pthread_mutex_lock(&philo->vars->mutex);
	philo->last_eat = get_time() - philo->vars->start;
	philo->soon_dead = philo->last_eat + philo->vars->ti_die;
	pthread_mutex_unlock(&philo->vars->mutex);
	ft_usleep(philo->vars->ti_eat, philo);
	pthread_mutex_lock(&philo->vars->mutex);
	if (philo->count > -1)
		philo->count++;
	pthread_mutex_unlock(&philo->vars->mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeping(t_philo *philo)
{
	display_message(philo, "is sleeping");
	ft_usleep(philo->vars->ti_sleep, philo);
}

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	display_message(philo, "has taken a fork");
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (0);
		}
		display_message(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
		display_message(philo, "has taken a fork");
	}
	return (1);
}
