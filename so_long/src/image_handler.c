/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/12/20 12:02:18 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

void	init_image(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	game->img->wfloor = mlx_xpm_file_to_image(game->mlx,
			"media/Wfloor.xpm", &game->img->width, &game->img->height);
	game->img->wwall = mlx_xpm_file_to_image(game->mlx,
			"media/Wwall.xpm", &game->img->width, &game->img->height);
	game->img->pfront = mlx_xpm_file_to_image(game->mlx,
			"media/Pfront.xpm", &game->img->width, &game->img->height);
	game->img->pback = mlx_xpm_file_to_image(game->mlx,
			"media/Pback.xpm", &game->img->width, &game->img->height);
	game->img->pleft = mlx_xpm_file_to_image(game->mlx,
			"media/Pleft.xpm", &game->img->width, &game->img->height);
	game->img->pright = mlx_xpm_file_to_image(game->mlx,
			"media/Pright.xpm", &game->img->width, &game->img->height);
	game->img->cexit = mlx_xpm_file_to_image(game->mlx,
			"media/Cexit.xpm", &game->img->width, &game->img->height);
	game->img->oexit = mlx_xpm_file_to_image(game->mlx,
			"media/Oexit.xpm", &game->img->width, &game->img->height);
	game->img->coin = mlx_xpm_file_to_image(game->mlx,
			"media/coin.xpm", &game->img->width, &game->img->height);
	game->img->pstart = mlx_xpm_file_to_image(game->mlx,
			"media/Pfront.xpm", &game->img->width, &game->img->height);
}

static void	put_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wwall, j * WIDTH, i * HEIGHT);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->pstart, j * WIDTH, i * HEIGHT);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->coin, j * WIDTH, i * HEIGHT);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->cexit, j * WIDTH, i * HEIGHT);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wfloor, j * WIDTH, i * HEIGHT);
}

void	ft_visualize(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			put_images(game, i, j);
		}
	}
}
