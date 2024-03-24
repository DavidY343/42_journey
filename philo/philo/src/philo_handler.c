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

//[philo->id % philo->datacpy->nphilos]); es el left y el otro el right
static void	philo_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->datacpy
			->forks[philo->id % philo->datacpy->nphilos]);
		printf("%lld %d has taken a fork\n", current_time()
			- philo->datacpy->initial_time, philo->id);
		pthread_mutex_lock(&philo->datacpy
			->forks[(philo->id + 1) % philo->datacpy->nphilos]);
		printf("%lld %d has taken a fork\n", current_time()
			- philo->datacpy->initial_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->datacpy
			->forks[(philo->id + 1) % philo->datacpy->nphilos]);
		printf("%lld %d has taken a fork\n", current_time()
			- philo->datacpy->initial_time, philo->id);
		pthread_mutex_lock(&philo->datacpy
			->forks[philo->id % philo->datacpy->nphilos]);
		printf("%lld %d has taken a fork\n", current_time()
			- philo->datacpy->initial_time, philo->id);
	}
}

static void	philo_eat_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->datacpy->m_eating);
	printf("%lld %d is eating\n", current_time()
		- philo->datacpy->initial_time, philo->id);
	philo->is_eating = 1;
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->datacpy->m_eating);
	usleep(philo->datacpy->teat * 1000);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->datacpy
		->forks[philo->id % philo->datacpy->nphilos]);
	pthread_mutex_unlock(&philo->datacpy
		->forks[(philo->id + 1) % philo->datacpy->nphilos]);
	usleep(philo->datacpy->tsleep * 1000);
	printf("%lld %d is thinking\n", current_time()
		- philo->datacpy->initial_time, philo->id);
}

void	*do_philo(void *philosopher)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philosopher;
	i = 0;
	if (philo->id % 2 == 0)
		usleep(philo->datacpy->teat - 1);
	while (!philo->datacpy->stop
		&& (philo->datacpy->neat == -1 || i < philo->datacpy->neat))
	{
		philo_fork(philo);
		philo_eat_think(philo);
		i++;
	}
	return (NULL);
}
