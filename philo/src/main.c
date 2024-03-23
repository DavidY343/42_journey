

#include "../headers/philo.h"

static void	*monitor_philo(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (!philo->datacpy->stop)
	{
		pthread_mutex_lock(&philo->datacpy->m_stop);
		pthread_mutex_lock(&philo->datacpy->m_eating);		
		if (!philo->is_eating && current_time() - philo->last_meal > philo->datacpy->tdie)
		{
			printf("%lld %d died\n", current_time() - philo->datacpy->initial_time, philo->id);
			philo->datacpy->stop = 1;
			pthread_mutex_unlock(&philo->datacpy->m_stop);
			pthread_mutex_unlock(&philo->datacpy->m_eating);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->datacpy->m_stop);
		pthread_mutex_unlock(&philo->datacpy->m_eating);
		usleep(1000);
	}
	return (NULL);
}


static int	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, do_philo, &data->philos[i]) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		if (pthread_create(&data->philos[i].monitor_thread_id, NULL, monitor_philo, &data->philos[i]) != 0)
		{
			printf("Error creating monitor thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
		{
			printf("Error waiting thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	// Destruye los mutexes
	while(i < data->nphilos)
	{
        pthread_mutex_destroy(&data->forks[i]);
		i++;
    }
	pthread_mutex_destroy(&data->m_eating);
	pthread_mutex_destroy(&data->m_printf);
	pthread_mutex_destroy(&data->m_stop);
	pthread_mutex_destroy(&data->dead);
    // Libera la memoria asignada para los filósofos y los mutexes
    free(data->philos);
    free(data->forks);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("Not the right arguments\n");
		return (1);
	}
	if (input_handler(argv) != 0)
		return (1);
	if (init_data(&data, argv) != 0)
		return (1);
	if (thread_handler(&data) != 0)
		return (1);
	return (0);
}
