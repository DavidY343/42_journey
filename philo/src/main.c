

#include "../headers/philo.h"

int do_philo(t_data *data)
{

}

static int	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, &do_philo, &data->philos[i]) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->nphilos)
	{
		if (pthread_join(&data->philos[i].thread_id, NULL) != 0)
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
	t_philo	philo;
	t_data	data;

	if (argc != 5 && argc != 4)
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
