
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
	int	id;
} t_philo;

typedef struct s_data
{
	/* data */
} t_data;


//INPUT_HANDLER.C
int		input_handler(char **inputs);

//UTILS.C
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
# endif