/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/11/10 02:44:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/so_long.h"

void	init_image(t_game *game)
{
	game->img = (t_img*)malloc(sizeof(t_img));
	game->img->bfloor = mlx_xpm_file_to_image(game->mlx, "../media/SueloOscuro.xpm", &game->img->width, &game->img->height);
	game->img->wfloor = mlx_xpm_file_to_image(game->mlx, "../media/SueloClaro.xpm", &game->img->width, &game->img->height);
	game->img->bwall = mlx_xpm_file_to_image(game->mlx, "../media/MuroOscuro.xpm", &game->img->width, &game->img->height);
	game->img->wwall = mlx_xpm_file_to_image(game->mlx, "../media/MuroClaro.xpm", &game->img->width, &game->img->height);
}

void 	ft_visualize(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((i == 0 || j == 0 || i == (game->height - 1) || j == (game->width - 1)))
			{
				if ((i + j) % 2 == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->img->bwall, i * 32, j * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->img->wwall, i * 32, j * 32);
			}
			else
			{
				if ((i + j) % 2 == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->img->bfloor, i * 32, j * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->img->wfloor, i * 32, j * 32);
			}
		}
		
	}
	
}