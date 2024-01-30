

#include "../headers/philo.h"

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
	return (0);
}
