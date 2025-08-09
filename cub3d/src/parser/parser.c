/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:29:09 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 17:05:57 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	player_pos(t_parse *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->fixed_map[i])
	{
		j = 0;
		while (map->fixed_map[i][j])
		{
			if (map->fixed_map[i][j] == 'N' || map->fixed_map[i][j] == 'S'
				|| map->fixed_map[i][j] == 'W' || map->fixed_map[i][j] == 'E')
			{
				map->pos_x = j;
				map->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	check_map_name(char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.');
	return (extension && !ft_strcmp(extension, ".cub"));
}

int	parser(int ac, char **av, t_parse *map)
{
	if (ac != 2 || !check_map_name(av[1]))
	{
		ft_putstr_fd("Error: invalid argument\n", 2);
		exit (1);
	}
	map->count = 0;
	if (!read_file(av[1], map))
		exit (1);
	if (!map_data(map))
		exit (1);
	map->texture_s = NULL;
	if (!fill_texture_s(&map))
	{
		free_map(map);
		exit (1);
	}
	if (!fill_color(&map))
	{
		free_map(map);
		exit (1);
	}
	player_pos(map);
	return (1);
}
