/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:00:58 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/18 17:35:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static char	*match_len(char *map_line, int longest)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = ft_calloc(sizeof(char), (longest + 1));
	if (!new_line)
		return (ft_putstr_fd("Error: calloc fail\n", 2), NULL);
	while (map_line[i])
	{
		if (map_line[i] == ' ')
			new_line[i] = '1';
		else
			new_line[i] = map_line[i];
		i++;
	}
	while (i < longest)
	{
		new_line[i] = '1';
		i++;
	}
	return (new_line);
}

int	map_data(t_parse *map)
{
	int	i;
	int	longest;

	longest = longest_line(map->map_2d);
	map->fixed_map = ft_calloc(sizeof(char *), (ft_len_arr(map->map_2d) + 1));
	if (!map->fixed_map)
		return (ft_putstr_fd("Error: calloc fail\n", 2), 0);
	i = -1;
	while (map->map_2d[++i])
	{
		map->fixed_map[i] = match_len(map->map_2d[i], longest);
		if (!map->fixed_map[i])
			return (free_map(map), 0);
	}
	map->height = ft_len_arr(map->fixed_map);
	map->width = ft_strlen(map->fixed_map[0]);
	return (1);
}
