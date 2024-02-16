
#include "../headers/philo.h"

static void philo_fork(t_philo  *philo)
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
}

void	*do_philo(void *philosopher)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		usleep(philo->datacpy->teat / 10);
    while (!philo->datacpy->stop && (philo->datacpy->neat == -1 || i < philo->datacpy->neat))
    {
        philo_fork(philo);
        printf("%lld %d is eating\n", current_time() - philo->datacpy->initial_time, philo->id);
        philo->is_eating = 1;
        usleep(philo->datacpy->teat * 1000);
        philo->last_meal = current_time();
        printf("%lld %d is sleeping\n", current_time() - philo->datacpy->initial_time, philo->id);
        philo->is_eating = 0;
        pthread_mutex_unlock(&philo->datacpy->forks[philo->id % philo->datacpy->nphilos]); // left fork
        pthread_mutex_unlock(&philo->datacpy->forks[(philo->id + 1) % philo->datacpy->nphilos]); // right fork
        usleep(philo->datacpy->tsleep * 1000);
        printf("%lld %d is thinking\n", current_time() - philo->datacpy->initial_time, philo->id);
        i++;
    }
	return (NULL);
}