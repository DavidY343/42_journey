/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:46:29 by jonjimen          #+#    #+#             */
/*   Updated: 2025/01/17 18:21:42 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	check_up(t_parse *map, int *j)
{
	int	i;

	i = 0;
	while (map->map_2d[i])
	{
		if ((size_t)(*j) <= ft_strlen(map->map_2d[i]) - 1)
		{
			if (map->map_2d[i][*j] == '1' || map->map_2d[i][*j] == 32)
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_down(t_parse *map, int *j)
{
	int	i;

	i = ft_len_arr(map->map_2d) - 1;
	while (i >= 0)
	{
		if ((size_t)(*j) <= ft_strlen(map->map_2d[i]) - 1)
		{
			if (map->map_2d[i][*j] == '1' || map->map_2d[i][*j] == 32)
				return (1);
			return (0);
		}
		i--;
	}
	return (1);
}

static int	check_line_1(t_parse *map, int *j)
{
	int	up;
	int	down;

	up = check_up(map, j);
	down = check_down(map, j);
	if (up == 0 || down == 0)
		return (0);
	return (1);
}

static int	check_colums_1(char **m)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (m[++i])
	{
		j = -1;
		if (((m[i][0] != '1' && m[i][0] != 32)
		|| (m[i][ft_len(m[i]) - 1] != '1' && m[i][ft_len(m[i]) - 1] != 32)))
			return (ft_putstr_fd("Error: map should be close 1\n", 2), 0);
		while (m[i][++j])
		{
			if (m[i][j] == 'W' || m[i][j] == 'E' || m[i][j] == 'N'
					|| m[i][j] == 'S')
				count++;
			else if ((m[i][j] != '1' && m[i][j] != 32 && m[i][j] != '0'
					&& m[i][j] != '\n'))
				return (ft_putstr_fd("Error: map not valid\n", 2), 0);
		}
	}
	if (count != 1)
		return (ft_putstr_fd("Error: needed exactly one player\n", 2), 0);
	return (1);
}

int	check_close_map(t_parse *map)
{
	int	j;

	j = 0;
	if (!map->map_2d[0])
		return (ft_putstr_fd("Error: empty map\n", 2), 0);
	while (j < longest_line(map->map_2d))
	{
		if (!check_line_1(map, &j))
			return (ft_putstr_fd("Error: map should be close 2\n", 2), 0);
		j++;
	}
	if (!check_colums_1(map->map_2d))
		return (0);
	return (1);
}
