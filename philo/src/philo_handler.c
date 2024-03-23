
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

static void philo_eat_think(t_philo *philo)
{
    pthread_mutex_lock(&philo->datacpy->m_eating); // Bloquea el mutex antes de acceder a las variables compartidas
    printf("%lld %d is eating\n", current_time() - philo->datacpy->initial_time, philo->id);
    philo->is_eating = 1;
    philo->last_meal = current_time();
    pthread_mutex_unlock(&philo->datacpy->m_eating); // Desbloquea el mutex después de acceder a las variables compartidas
    usleep(philo->datacpy->teat * 1000);
    philo->is_eating = 0;
    pthread_mutex_unlock(&philo->datacpy->forks[philo->id % philo->datacpy->nphilos]); // left fork
    pthread_mutex_unlock(&philo->datacpy->forks[(philo->id + 1) % philo->datacpy->nphilos]); // right fork
    usleep(philo->datacpy->tsleep * 1000);
    printf("%lld %d is thinking\n", current_time() - philo->datacpy->initial_time, philo->id);
}

void *do_philo(void *philosopher)
{
    t_philo *philo = (t_philo *)philosopher;
    int i = 0;
    if (philo->id % 2 == 0)
        usleep(philo->datacpy->teat - 1);
    while (!philo->datacpy->stop && (philo->datacpy->neat == -1 || i < philo->datacpy->neat))
	{
        philo_fork(philo);
        philo_eat_think(philo);
        i++;
    }
    return NULL;
}