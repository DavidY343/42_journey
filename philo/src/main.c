

#include "../headers/philo.h"

static void	*do_philo(void *philosopher)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philosopher;
	
    while (philo->datacpy->neat == -1 || i < philo->datacpy->neat)
    {
        if (philo->id % 2 == 0)
		{
            pthread_mutex_lock(&philo->datacpy->forks[philo->id % philo->datacpy->nphilos]); // left fork
			printf("%lld %d has taken a fork\n", current_time() - philo->datacpy->initial_time, philo->id);
            pthread_mutex_lock(&philo->datacpy->forks[(philo->id + 1) % philo->datacpy->nphilos]); // right fork
			printf("%lld %d has taken a fork\n", current_time() - philo->datacpy->initial_time, philo->id);
        }
		else
		{
            pthread_mutex_lock(&philo->datacpy->forks[(philo->id + 1) % philo->datacpy->nphilos]); // right fork
			printf("%lld %d has taken a fork\n", current_time() - philo->datacpy->initial_time, philo->id);
            pthread_mutex_lock(&philo->datacpy->forks[philo->id % philo->datacpy->nphilos]); // left fork
			printf("%lld %d has taken a fork\n", current_time() - philo->datacpy->initial_time, philo->id);
        }
		
        printf("%lld %d is eating\n", current_time() - philo->datacpy->initial_time, philo->id);
        usleep(philo->datacpy->teat * 1000);
        printf("%lld %d is sleeping\n", current_time() - philo->datacpy->initial_time, philo->id);
        pthread_mutex_unlock(&philo->datacpy->forks[philo->id % philo->datacpy->nphilos]); // left fork
        pthread_mutex_unlock(&philo->datacpy->forks[(philo->id + 1) % philo->datacpy->nphilos]); // right fork
        usleep(philo->datacpy->tsleep * 1000);
        printf("%lld %d is thinking\n", current_time() - philo->datacpy->initial_time, philo->id);
        i++;
    }
	return (NULL);
}

static int	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	usleep(5000);
	while (i < data->nphilos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, do_philo, &data->philos[i]) != 0)
		{
			printf("Error creating thread\n");
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
