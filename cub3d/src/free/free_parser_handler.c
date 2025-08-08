/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:08:10 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 18:21:33 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_temp(t_parse *map)
{
	if (map->texture)
	{
		free(map->texture);
		map->texture = NULL;
	}
	if (map->line)
	{
		free(map->line);
		map->line = NULL;
	}
	if (map->fd >= 0)
		close(map->fd);
}

void	free_temp_2d(t_parse *map)
{
	int	i;

	free_temp(map);
	if (map->map)
	{
		free(map->map);
		map->map = NULL;
	}
	i = 0;
	while (map->map_2d && map->map_2d[i])
	{
		free(map->map_2d[i]);
		map->map_2d[i++] = NULL;
	}
	free(map->map_2d);
	map->map_2d = NULL;
}

void	free_double(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i++] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	free_map(t_parse *map)
{
	t_texture	*temp;

	free_double(map->fixed_map);
	free_temp_2d(map);
	free_double(map->texture_2d);
	if (map->ff)
		free_double(map->ff);
	if (map->cc)
		free_double(map->cc);
	temp = map->texture_s;
	while (temp)
	{
		map->texture_s = temp->next;
		if (temp->name)
			free(temp->name);
		if (temp->value)
			free(temp->value);
		if (temp)
			free(temp);
		temp = map->texture_s;
	}
	if (map->texture_s)
		free(map->texture_s);
}
