/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_s_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:14:34 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:21 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	check_values(char **color)
{
	int	i;

	i = -1;
	while (color[++i])
		if (ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
			return (free_double(color), 0);
	return (free_double(color), 1);
}

static void	get_color(t_texture *color, t_parse **map)
{
	if (!ft_strncmp(color->name, "F", 2))
		(*map)->ff = ft_split(color->value, ',');
	else if (!ft_strncmp(color->name, "C", 2))
		(*map)->cc = ft_split(color->value, ',');
	return ;
}

int	fill_color(t_parse **map)
{
	t_texture	*temp;

	(*map)->cc = NULL;
	(*map)->ff = NULL;
	temp = (*map)->texture_s;
	while (temp)
	{
		if (!ft_strncmp(temp->name, "F", 1) || !ft_strncmp(temp->name, "C", 1))
		{
			if (!check_values(ft_split(temp->value, ',')))
				return (ft_putstr_fd("Error: invalid map color\n", 2), 0);
			get_color(temp, map);
		}
		temp = temp->next;
	}
	return (1);
}
