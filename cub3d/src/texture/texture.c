/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:41:25 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:35 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	check_texture_type(char *line)
{
	while (check_space(*line))
		line++;
	return ((!ft_strncmp(line, "EA", 2) || !ft_strncmp(line, "NO", 2)
			|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2))
		|| (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)));
}

void	get_texture(t_parse *map)
{
	char	*temp;

	while (map->line && map->line[0] != '1' && map->line[0] != 32)
	{
		if (check_texture_type(map->line))
		{
			temp = ft_strjoin(map->texture, map->line);
			if (map->texture)
				free(map->texture);
			map->texture = strdup(temp);
			if (temp)
				free(temp);
			map->count++;
		}
		if (map->line)
			free(map->line);
		map->line = get_next_line(map->fd);
	}
}

static int	is_valid_texture(char *text)
{
	while (check_space(*text))
		text++;
	if ((!ft_strncmp(text, "NO", 2) || !ft_strncmp(text, "SO", 2)
			|| !ft_strncmp(text, "WE", 2) || !ft_strncmp(text, "EA", 2))
		&& check_space(text[2]))
		return (1);
	else if ((!ft_strncmp(text, "F", 1) || !ft_strncmp(text, "C", 1))
		&& check_space(text[1]))
		return (1);
	return (0);
}

int	check_textures(t_parse *map)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++i < map->count)
		if (!is_valid_texture(map->texture_2d[i]))
			return (ft_putstr_fd("Error: wrong textures\n", 2), 0);
	while (map->texture_2d[j])
	{
		k = j + 1;
		while (map->texture_2d[k])
		{
			if (!ft_strncmp(map->texture_2d[j], map->texture_2d[k], 2))
				return (ft_putstr_fd("Error: duplicate textures\n", 2), 0);
			k++;
		}
		j++;
	}
	return (1);
}

int	check_colors(t_parse *map)
{
	int		i;
	char	*temp;

	i = 0;
	while (map->texture_2d[i])
	{
		temp = map->texture_2d[i];
		while (check_space(*temp))
			temp++;
		if (temp[0] == 'F' || temp[0] == 'C')
			if (!check_floor_ceiling(temp))
				return (ft_putstr_fd("Error: wrong colors\n", 2), 0);
		i++;
	}
	return (1);
}
