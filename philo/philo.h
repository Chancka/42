/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:04:39 by cboudrin          #+#    #+#             */
/*   Updated: 2022/06/14 12:52:49 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_philo
{
	pthread_t		id_thread;
	int				id;
	int				is_eating;
	int				last_eat;
	int				is_sleeping;
	int				count;
	int				soon_dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_vars	*vars;
}					t_philo;

typedef struct		s_vars
{
	int				nb_philo;
	int				is_dead;
	int  			ti_die;
	int				ti_eat;
	int				ti_sleep;
	int				amount_loop;
	int				start;
	t_philo			*philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
}					t_vars;

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		check_args(char **argv);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		init_vars(t_vars *vars, char **argv);
int		init_threads(t_vars *vars);
void	*routine(void *philo);
int		get_time(void);
int		take_forks(t_philo *philo);
void	sleeping(t_philo *philo);
int		kill_philo(t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
int		is_dead(t_philo *philo);
void	display_message(t_philo *philo, char *message);
void	ft_usleep(int time, t_philo *philo);

#endif
