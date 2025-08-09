/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:16:52 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/08/18 11:50:54 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	counter;
	int	*number;
	int	i;

	i = 0;
	counter = max - min;
	if (min >= max)
		return (0);
	number = (int *)malloc(counter * sizeof(int));
	while (i < counter)
	{
		number[i] = min + i;
		i++;
	}
	return (number);
}
