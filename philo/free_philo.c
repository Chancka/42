/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:49:08 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/20 12:49:16 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
