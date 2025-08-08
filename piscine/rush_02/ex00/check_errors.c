/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalah-d <lsalah-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:10:12 by lsalah-d          #+#    #+#             */
/*   Updated: 2023/08/27 19:24:25 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int	check_argc(int argc)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	else
		return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	else
		return (0);
}
