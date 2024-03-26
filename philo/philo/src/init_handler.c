/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:27:12 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/03/26 19:01:11 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

/*DEBERIA LIBERAR LA MEMORIA CADA VEZ QUE ENCUENTRE UN ERROR, DUDA*/
static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->m_stop, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->m_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->m_finish, NULL) != 0)
		return (1);
	while (i < data->nphilos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Init error forks\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->stop = 0;
	while (i < data->nphilos)
	{
		if (pthread_mutex_init(&data->philos[i].m_eating, NULL) != 0)
		{
			printf("Init eating mutex\n");
			return (1);
		}
		data->philos[i].finished = 0;
		data->philos[i].id = i;
		data->philos[i].datacpy = data;
		data->philos[i].last_meal = current_time();
		data->philos[i].is_eating = 0;
		data->philos[i].l_fork = i;
		data->philos[i].r_fork = (i + 1) % data->nphilos;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->nphilos = ft_atoi(argv[1]);
	data->tdie = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	if (argv[5])
		data->neat = ft_atoi(argv[5]);
	else
		data->neat = -1;
	data->initial_time = current_time();
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nphilos);
	if (!data->philos)
	{
		printf("Allocating memory error philos\n");
		return (1);
	}
	data->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->nphilos);
	if (!data->forks)
	{
		printf("Allocating memory error forks\n");
		return (1);
	}
	if (init_mutex(data) != 0 || init_philos(data) != 0)
		return (1);
	return (0);
}
