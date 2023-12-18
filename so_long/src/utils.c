/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:57:10 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/18 18:58:13 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	count_char(char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
