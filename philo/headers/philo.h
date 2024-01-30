
# ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	pthread_t			thread_id;
} t_philo;

typedef struct s_data
{
	int	nphilos;
	int	tdie;
	int	teat;
	int tsleep;
	int neat;
	t_philo	*philos;
	pthread_mutex_t	*forks;
} t_data;


//INPUT_HANDLER.C
int		input_handler(char **inputs);

//UTILS.C
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);

//INIT_HANDLER.C
int	init_data(t_data *data, char **argv);

//TIME_HANDLER.C
long long	current_time(void);

# endif