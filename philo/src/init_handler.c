

#include "../headers/philo.h"


/*POR LO GENERAL DEBERIA LIBERAR LA MEMORIA CADA VEZ QUE ENCUENTRE UN ERROR, PENDIENTE DE VALORACION*/
static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
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
	while(i < data->nphilos)
	{
		// Lo que tenga cada philo
		data->philos->neat = data->neat;
		data->philos->tdie = data->tdie;
		data->philos->teat = data->teat;
		data->philos->tsleep = data->tsleep;
		data->philos->nphilos = data->nphilos;
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
