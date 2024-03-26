/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:52:05 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/03/24 17:59:15 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	philo_eat_think_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->datacpy->forks[philo->l_fork]));
	my_print(philo->datacpy, philo->id, "has taken a fork");
	if (philo->datacpy->nphilos == 1)
	{
		usleep(philo->datacpy->tdie * 1000);
		pthread_mutex_unlock(&(philo->datacpy->forks[philo->l_fork]));
		return ;
	}
	pthread_mutex_lock(&(philo->datacpy->forks[philo->r_fork]));
	my_print(philo->datacpy, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->m_eating);
	my_print(philo->datacpy, philo->id, "is eating");
	philo->is_eating = 1;
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->m_eating);
	usleep(philo->datacpy->teat * 1000);
	pthread_mutex_lock(&philo->m_eating);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->m_eating);
	pthread_mutex_unlock(&(philo->datacpy->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->datacpy->forks[philo->l_fork]));
	my_print(philo->datacpy, philo->id, "is sleeping");
	usleep(philo->datacpy->tsleep * 1000);
	my_print(philo->datacpy, philo->id, "is thinking");
}

void	*do_philo(void *philosopher)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philosopher;
	i = 0;
	if ((philo->id - 1) % 2 == 0)
		usleep((philo->datacpy->teat - 1) * 1000);
	pthread_mutex_lock(&philo->datacpy->m_stop);
	while (!philo->datacpy->stop
		&& (philo->datacpy->neat == -1 || i < philo->datacpy->neat))
	{
		pthread_mutex_unlock(&philo->datacpy->m_stop);
		philo_eat_think_sleep(philo);
		i++;
		pthread_mutex_lock(&philo->datacpy->m_stop);
	}
	pthread_mutex_unlock(&philo->datacpy->m_stop);
	return (NULL);
}
