/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:11:24 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/19 00:18:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

int	flood_fill(int x, int y, t_prs *prs, char **map)
{
	if (x < 0 || x >= (prs->height - 1) || y < 0 || y >= (prs->width - 1))
		return (0);
	if (map[x][y] == 'E')
		prs->exit = 1;
	if (prs->exit == 1 && prs->c_coins == prs->coins)
		return (1);
	else if (map[x][y] == '0' || map[x][y] == 'P'
			|| map[x][y] == 'C')
	{
		if (map[x][y] == 'C')
			prs->c_coins++;
		map[x][y] = '.';
		if (flood_fill(x + 1, y, prs, map) || flood_fill(x - 1, y, prs, map)
			|| flood_fill(x, y + 1, prs, map)
			|| flood_fill(x, y - 1, prs, map))
			return (1);
	}
	return (0);
}

/*
static void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}*/

static void	change_prs_to_game(t_prs *prs, t_game *game)
{
	int	i;

	i = -1;
	game->map = (char **)malloc((prs->height + 1) * sizeof(char *));
	while (++i < prs->height)
	{
		game->map[i] = ft_strdup(prs->map[i]);
	}
	game->map[prs->height] = NULL;
	game->width = prs->width;
	game->height = prs->height;
	game->coins = prs->coins;
	free_map(prs->map);
}

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		msg_error("Map doesn't init\n");
	init_image(game);
	game->win = mlx_new_window(game->mlx, game->width * WIDTH,
			game->height * HEIGHT, "so_long");
	ft_visualize(game);
	mlx_key_hook(game->win, key_handler, game);
	//mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(game->mlx);
	msg_error("Error inesperado\n");
}

int	main(int argc, char **argv)
{
	t_prs	prs;
	t_game	game;

	check_inputs(argc, argv, &prs);
	change_prs_to_game(&prs, &game);
	init_game(&game);
	return (0);
}
