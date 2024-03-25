/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:04:08 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/03/24 17:08:56 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				is_eating;
	pthread_t		thread_id;
	pthread_t		monitor_thread_id;
	long long		last_meal;
	pthread_mutex_t	m_eating;
	int				l_fork;
	int				r_fork;
	struct s_data	*datacpy;
}	t_philo;

typedef struct s_data
{
	int				nphilos;
	int				tdie;
	int				teat;
	int				tsleep;
	int				neat;
	int				stop;
	t_philo			*philos;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*forks;
	long long		initial_time;
}	t_data;

//INPUT_HANDLER.C
int			input_handler(char **inputs);

//UTILS.C
int			ft_atoi(const char *nptr);
size_t		ft_strlen(const char *str);
long long	current_time(void);
void		my_print(t_data *data, int id, char *message);

//INIT_HANDLER.C
int			init_data(t_data *data, char **argv);

//PHILO_HANDLER.C
void		*do_philo(void *philosopher);

#endif