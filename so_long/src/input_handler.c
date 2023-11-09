/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:09:26 by david             #+#    #+#             */
/*   Updated: 2023/11/09 18:15:42 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
/*
static void	print_map(t_data *data)
{
	int i = 0;
	while (data->map[i] != 0)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}*/
static void	check_border(t_data *data, char **cpy_map)
{
	int	i;
	int	j;

	i = -1;
	while (data && data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				if (flood_fill(i, j, data, cpy_map) == 0)
					msg_error_map("No possible solution\n", data->map);
			}
			if (data->map[i][j] != '1' && data->map[i][j] != '0' && data->map[i]
				[j] != 'C' && data->map[i][j] != 'P' && data->map[i][j] != 'E')
				msg_error_map("Map isn't built a 1, 0, E, P, C\n", data->map);
			else if ((i == 0 || j == 0 || i == (data->height - 1)
					|| j == (data->width - 1)) && data->map[i][j] != '1')
				msg_error_map("The map isn't surrounded by walls\n", data->map);
		}
	}
}

static void	get_max_x_y(t_data *data)
{
	int	i;

	i = -1;
	data->height = -1;
	data->width = ft_strlen2(data->map[0]);
	while (data && data->map[++i])
	{
		if (data->width != (int)ft_strlen2(data->map[i]))
			msg_error_map("The map isn't a perfect rectangle\n", data->map);
	}
	data->height = i;
	if (data->height == data->width)
		msg_error_map("The square map is not valid\n", data->map);
}

static void	check_map(t_data *data)
{
	int	i;
	int	player;
	int	exit;

	i = -1;
	player = 0;
	exit = 0;
	data->coins = 0;
	data->c_coins = 0;
	data->exit = 0;
	if (!data || !data->map)
		msg_error("Empty map\n");
	while (data && data->map[++i])
	{
		exit += count_char(data->map[i], 'E');
		data->coins += count_char(data->map[i], 'C');
		player += count_char(data->map[i], 'P');
	}
	if (player != 1)
		msg_error_map("You must've only 1 Player on the Map\n", data->map);
	if (exit != 1)
		msg_error_map("You must've only 1 Exit on the Map\n", data->map);
	if (data->coins <= 0)
		msg_error_map("You must've at least 1 Coin on the Map\n", data->map);
}

static void	read_map(int fd, t_data *data)
{
	char	*line;
	char	*map_str;
	char	**cpy_map;

	line = NULL;
	map_str = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_str = ft_strjoin2(map_str, line);
		free(line);
	}
	close(fd);
	data->map = ft_split(map_str, '\n');
	cpy_map = ft_split(map_str, '\n');
	free(map_str);
	check_map(data);
	get_max_x_y(data);
	check_border(data, cpy_map);
	free_map(cpy_map);
}

void	check_inputs(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		msg_error("You must run it with only one parameter!\n");
	if (ft_strrncmp(argv[1], ".ber", 4) != 0)
		msg_error("You must include a ber file!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg_error_param("No such file or directory: ", argv[1]);
	read_map(fd, data);
	free_map(data->map);
}
