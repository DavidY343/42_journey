/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:09:26 by david             #+#    #+#             */
/*   Updated: 2023/12/21 14:09:52 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
/*
static void	print_map(t_prs *prs)
{
	int i = 0;
	while (prs->map[i] != 0)
	{
		printf("%s\n", prs->map[i]);
		i++;
	}
}*/
static void	check_border(t_prs *prs, char **cpy_map)
{
	int	i;
	int	j;

	i = -1;
	while (prs && prs->map[++i])
	{
		j = -1;
		while (prs->map[i][++j])
		{
			if (prs->map[i][j] == 'P')
			{
				if (flood_fill(i, j, prs, cpy_map) == 0)
					msg_error_map("No possible solution\n", prs->map);
			}
			if (prs->map[i][j] != '1' && prs->map[i][j] != '0' && prs->map[i]
				[j] != 'C' && prs->map[i][j] != 'P' && prs->map[i][j] != 'E'
				&& prs->map[i][j] != 'G')
				msg_error_map("Map not built as 1, 0, E, P, C, G\n", prs->map);
			else if ((i == 0 || j == 0 || i == (prs->height - 1)
					|| j == (prs->width - 1)) && prs->map[i][j] != '1')
				msg_error_map("The map isn't surrounded by walls\n", prs->map);
		}
	}
}

/*	if (prs->height == prs->width)
		msg_error_map("The square map is not valid\n", prs->map);*/
static void	get_max_x_y(t_prs *prs)
{
	int	i;

	i = -1;
	prs->height = -1;
	prs->width = ft_strlen2(prs->map[0]);
	while (prs && prs->map[++i])
	{
		if (prs->width != (int)ft_strlen2(prs->map[i]))
			msg_error_map("The map isn't rectangular\n", prs->map);
	}
	if (prs->width > 80)
		msg_error_map("The map exceeded the screen's width limit.\n", prs->map);
	prs->height = i;
	if (prs->height > 45)
		msg_error_map("The map exceeded the screen height limit.\n", prs->map);
}

static void	check_map(t_prs *prs)
{
	int	i;
	int	player;
	int	exit;

	i = -1;
	player = 0;
	exit = 0;
	prs->coins = 0;
	prs->c_coins = 0;
	prs->exit = 0;
	if (!prs || !prs->map)
		msg_error("Empty map\n");
	while (prs && prs->map[++i])
	{
		exit += count_char(prs->map[i], 'E');
		prs->coins += count_char(prs->map[i], 'C');
		player += count_char(prs->map[i], 'P');
	}
	if (player != 1)
		msg_error_map("You must've only 1 Player on the Map\n", prs->map);
	if (exit != 1)
		msg_error_map("You must've only 1 Exit on the Map\n", prs->map);
	if (prs->coins <= 0)
		msg_error_map("You must've at least 1 Coin on the Map\n", prs->map);
}

static void	read_map(int fd, t_prs *prs)
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
	prs->map = ft_split(map_str, '\n');
	cpy_map = ft_split(map_str, '\n');
	free(map_str);
	check_map(prs);
	get_max_x_y(prs);
	check_border(prs, cpy_map);
	free_map(cpy_map);
}

void	check_inputs(int argc, char **argv, t_prs *prs)
{
	int	fd;

	if (argc != 2)
		msg_error("You must run it with only one parameter!\n");
	if (ft_strrncmp(argv[1], ".ber", 4) != 0)
		msg_error("You must include a ber file!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		msg_error_param("No such file or directory: ", argv[1]);
	read_map(fd, prs);
}
