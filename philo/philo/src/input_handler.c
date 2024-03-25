/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:51:27 by dyanez-m          #+#    #+#             */
/*   Updated: 2024/03/24 17:51:55 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

static int	input_handler_two(char **inputs)
{
	int	i;

	i = 2;
	while (i < 5)
	{
		if (ft_atoi(inputs[i]) < 1)
		{
			printf("Not valid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	input_handler(char **inputs)
{
	int	i;

	i = 1;
	while (inputs[i])
	{
		if (check_num(inputs[i]) == 0)
		{
			printf("Not a valid number\n");
			return (1);
		}
		i++;
	}
	if (ft_atoi(inputs[1]) < 1)
	{
		printf("At least 1 philo\n");
		return (1);
	}
	if (input_handler_two(inputs) == 1)
		return (1);
	return (0);
}
