

#include "../headers/philo.h"


/*POR LO GENERAL DEBERIA LIBERAR LA MEMORIA CADA VEZ QUE ENCUENTRE UN ERROR, PENDIENTE DE VALORACION*/
static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if(pthread_mutex_init(&data->m_stop, NULL) != 0)
	{
		printf("Init error mutex stop\n");
		return (1);
	}
	if(pthread_mutex_init(&data->m_eating, NULL) != 0)
	{
			printf("Init error mutex eating\n");
			return (1);
	}
	if(pthread_mutex_init(&data->m_printf, NULL) != 0)
	{
		printf("Init error mutex print\n");
		return (1);
	}
	if(pthread_mutex_init(&data->dead, NULL) != 0)
	{
		printf("Init error mutex dead\n");
		return (1);
	}
	while(i < data->nphilos)
	{
		if(pthread_mutex_init(&data->forks[i], NULL) != 0)
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
	while(i < data->nphilos)
	{
		// Lo que tenga cada philo
		data->philos[i].id = i;
		data->philos[i].datacpy = data;
		data->philos[i].last_meal = current_time();
		data->philos[i].is_eating = 0;
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
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nphilos);
	if (!data->forks)
	{
		printf("Allocating memory error forks\n");
		return (1);
	}
	if (init_mutex(data) != 0 || init_philos(data) != 0)
		return (1);
	return (0);
}
