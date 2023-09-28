/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:14:01 by david             #+#    #+#             */
/*   Updated: 2023/09/28 17:59:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '9' || str[i] <= '0')
			return (0);
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	*check_inputs_aux(char **argv, int i)
{
	long	number;
	int		*nbr;
	int		j;

	j = 0;
	while(argv[i] != 0)
		i++;
	nbr = (int *)malloc(sizeof(int) * i);
	if (!nbr)
		exit (0);
	i = 0;
	while (argv[i] != 0)
	{
		if (check_num(argv[i]) == 0)
		{
			ft_printf("Error\n");
			free(nbr);
			exit (-1);
		}
		number = ft_atoi(argv[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			ft_printf("Error\n");
			free(nbr);
			exit (-1);
		}
		nbr[j] = (int)number;
		i++;
	}
	return (nbr);
}

int	*check_inputs(int argc, char **argv)
{
	int	*nbr;

	if (argc < 2)
	{
		ft_printf("Error\n");
		exit (-1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		nbr = check_inputs_aux(argv, 0); 
		free(argv);
	}
	else
	{
		nbr = check_inputs_aux(argv, 1);
	}
	return (nbr);
}