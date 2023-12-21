/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:12:09 by david             #+#    #+#             */
/*   Updated: 2023/12/21 13:15:50 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
static void	free_image(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img->wwall);
    mlx_destroy_image(game->mlx, game->img->wfloor);
    mlx_destroy_image(game->mlx, game->img->pfront);
    mlx_destroy_image(game->mlx, game->img->pback);
    mlx_destroy_image(game->mlx, game->img->pleft);
    mlx_destroy_image(game->mlx, game->img->pright);
    mlx_destroy_image(game->mlx, game->img->cexit);
    mlx_destroy_image(game->mlx, game->img->oexit);
    mlx_destroy_image(game->mlx, game->img->coin1);
    mlx_destroy_image(game->mlx, game->img->coin2);
    mlx_destroy_image(game->mlx, game->img->coin3);
    mlx_destroy_image(game->mlx, game->img->coin4);
    mlx_destroy_image(game->mlx, game->img->coin5);
    mlx_destroy_image(game->mlx, game->img->coin6);
    mlx_destroy_image(game->mlx, game->img->coin7);
    mlx_destroy_image(game->mlx, game->img->coin8);
    free(game->img);
}
static void	free_game(t_game *game)
{
	if (game->img != NULL)
		free_image(game);
	free_map(game->map);
}

int	free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
	return (0);
}
