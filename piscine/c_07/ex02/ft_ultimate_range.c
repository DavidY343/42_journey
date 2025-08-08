/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:51:57 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/22 17:40:56 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	counter;
	int	i;
	int	*number;

	i = 0;
	counter = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	number = (int *)malloc(counter * sizeof(int));
	if (number == NULL)
		return (-1);
	while (i < counter)
	{
		number[i] = min + i;
		i++;
	}
	*range = number;
	return (counter);
}
