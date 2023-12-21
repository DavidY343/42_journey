/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/12/21 14:11:10 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/macros.h"

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
	else if (game->map[i][j] == 'G')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->gstart, j * WIDTH, i * HEIGHT);
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
