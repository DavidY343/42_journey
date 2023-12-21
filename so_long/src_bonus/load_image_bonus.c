/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:10:25 by david             #+#    #+#             */
/*   Updated: 2023/12/21 14:53:29 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
#include "../headers/macros.h"

static void	init_image_coin(t_game *game)
{
	game->img->coin = mlx_xpm_file_to_image(game->mlx,
			"media/coin1.xpm", &game->img->width, &game->img->height);
	game->img->coin1 = mlx_xpm_file_to_image(game->mlx,
			"media/coin1.xpm", &game->img->width, &game->img->height);
	game->img->coin2 = mlx_xpm_file_to_image(game->mlx,
			"media/coin2.xpm", &game->img->width, &game->img->height);
	game->img->coin3 = mlx_xpm_file_to_image(game->mlx,
			"media/coin3.xpm", &game->img->width, &game->img->height);
	game->img->coin4 = mlx_xpm_file_to_image(game->mlx,
			"media/coin4.xpm", &game->img->width, &game->img->height);
	game->img->coin5 = mlx_xpm_file_to_image(game->mlx,
			"media/coin5.xpm", &game->img->width, &game->img->height);
	game->img->coin6 = mlx_xpm_file_to_image(game->mlx,
			"media/coin6.xpm", &game->img->width, &game->img->height);
	game->img->coin7 = mlx_xpm_file_to_image(game->mlx,
			"media/coin7.xpm", &game->img->width, &game->img->height);
	game->img->coin8 = mlx_xpm_file_to_image(game->mlx,
			"media/coin8.xpm", &game->img->width, &game->img->height);
}

static void	init_image_goblin(t_game *game)
{
	game->img->gstart = mlx_xpm_file_to_image(game->mlx,
			"media/Gfront1.xpm", &game->img->width, &game->img->height);
	game->img->gfront1 = mlx_xpm_file_to_image(game->mlx,
			"media/Gfront1.xpm", &game->img->width, &game->img->height);
	game->img->gfront2 = mlx_xpm_file_to_image(game->mlx,
			"media/Gfront2.xpm", &game->img->width, &game->img->height);
	game->img->gfront3 = mlx_xpm_file_to_image(game->mlx,
			"media/Gfront3.xpm", &game->img->width, &game->img->height);
}

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
	game->img->pstart = mlx_xpm_file_to_image(game->mlx,
			"media/Pfront.xpm", &game->img->width, &game->img->height);
	init_image_coin(game);
	init_image_goblin(game);
}
