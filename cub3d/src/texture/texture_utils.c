/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:15:29 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 18:21:02 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	check_floor_ceiling_aux(char *temp, int *count)
{
	while (temp && *temp)
	{
		while (temp && *temp && ft_isdigit(*temp))
			temp++;
		if (temp && *temp && *temp != ',' && !ft_isdigit(*temp))
			return (0);
		if (temp && *temp == ',')
		{
			(*count)++;
			temp++;
		}
		(*count)++;
	}
	if (*count != 6)
		return (0);
	return (1);
}

int	check_floor_ceiling(char *temp)
{
	int	count;

	count = 0;
	while (temp && *temp
		&& (check_space(*temp) || *temp == 'C' || *temp == 'F'))
	{
		if (*temp == 'C' || *temp == 'F')
			count++;
		temp++;
	}
	if (count != 1)
		return (0);
	if (!check_floor_ceiling_aux(temp, &count))
		return (0);
	return (1);
}
