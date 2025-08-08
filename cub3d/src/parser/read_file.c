/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:17:37 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:11 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	save_map_aux(t_parse *map)
{
	char	*temp;

	map->map = ft_strdup("");
	while (map->line)
	{
		if (map->line[0] == '\n')
		{
			ft_putstr_fd("Error: map with empty line\n", 2);
			return (0);
		}
		temp = ft_strjoin(map->map, map->line);
		if (map->map)
			free(map->map);
		if (map->line)
			free(map->line);
		map->map = ft_strdup(temp);
		if (temp)
			free(temp);
		map->line = get_next_line(map->fd);
	}
	return (1);
}

static int	save_map(t_parse *map)
{
	if (!save_map_aux(map))
		return (0);
	if (!map->map)
		return (0);
	map->map_2d = ft_split(map->map, '\n');
	if (!map->map_2d)
		return (ft_putstr_fd("Error: map_2d split fail\n", 2), 0);
	if (map->map)
	{
		free(map->map);
		map->map = NULL;
	}
	if (!check_textures(map) || !check_colors(map)
		|| !check_close_map(map))
		return (0);
	return (1);
}

int	read_file(char *argv, t_parse *map)
{
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		return (ft_putstr_fd("Error: argument is not valid\n", 2), 0);
	map->line = get_next_line(map->fd);
	if (map->line == NULL)
		return (ft_putstr_fd("Error: file is empty\n", 2), 0);
	map->texture = ft_strdup("");
	get_texture(map);
	if (map->count != 6)
	{
		ft_putstr_fd("Error: missing textures\n", 2);
		return (free_temp(map), 0);
	}
	map->texture_2d = ft_split(map->texture, '\n');
	if (!map->texture_2d)
		return (ft_putstr_fd("Error: texture_2d split fail\n", 2), 0);
	map->map_2d = NULL;
	if (!save_map(map))
		return (free_temp_2d(map), free_double(map->texture_2d), 0);
	return (free_temp(map), 1);
}
