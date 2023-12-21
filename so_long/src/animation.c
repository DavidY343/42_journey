/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:43:47 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/21 13:17:04 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

static void	animate_coin(t_game *game)
{
	if (game->controlc == 0)
		game->img->coin = game->img->coin1;
	else if (game->controlc == 1)
		game->img->coin = game->img->coin1;
	else if (game->controlc == 2)
		game->img->coin = game->img->coin2;
	else if (game->controlc == 3)
		game->img->coin = game->img->coin3;
	else if (game->controlc == 4)
		game->img->coin = game->img->coin4;
	else if (game->controlc == 5)
		game->img->coin = game->img->coin5;
	else if (game->controlc == 6)
		game->img->coin = game->img->coin6;
	else if (game->controlc == 7)
		game->img->coin = game->img->coin7;
	else if (game->controlc == 8)
		game->img->coin = game->img->coin8;
	if (game->controlc < 8)
		game->controlc++;
	else
		game->controlc = 0;
}

int	animation(t_game *game)
{
	if (game->i > 1200)
	{
		animate_coin(game);
		ft_visualize(game);
		game->i = 0;
	}
	game->i++;
	return (0);
}
