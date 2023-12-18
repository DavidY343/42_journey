/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/12/18 19:21:25 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

void	init_image(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	game->img->bfloor = mlx_xpm_file_to_image(game->mlx,
			"media/SueloOscuro.xpm", &game->img->width, &game->img->height);
	game->img->wfloor = mlx_xpm_file_to_image(game->mlx,
			"media/SueloClaro.xpm", &game->img->width, &game->img->height);
	game->img->bwall = mlx_xpm_file_to_image(game->mlx,
			"media/MuroOscuro.xpm", &game->img->width, &game->img->height);
	game->img->wwall = mlx_xpm_file_to_image(game->mlx,
			"media/MuroClaro.xpm", &game->img->width, &game->img->height);
}

static void	white_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->wwall, j * WIDTH, i * HEIGHT);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->bfloor, j * WIDTH, i * HEIGHT);
}

static void	black_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->bwall, j * WIDTH, i * HEIGHT);
	else
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
			if ((i + j) % 2 == 0)
				white_images(game, i, j);
			else
				black_images(game, i, j);
		}
	}
}
