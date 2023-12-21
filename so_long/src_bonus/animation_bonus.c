/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:43:47 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/21 14:48:59 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"
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

static void	animate_goblin(t_game *game)
{
	if (game->controlg == 0 || game->controlg == 1 || game->controlg == 2)
		game->img->gstart = game->img->gfront1;
	else if (game->controlg == 3 || game->controlg == 4 || game->controlg == 5)
		game->img->gstart = game->img->gfront2;
	else if (game->controlg == 6 || game->controlg == 7 || game->controlg == 8)
		game->img->gstart = game->img->gfront3;
	if (game->controlg < 9)
		game->controlg++;
	else
		game->controlg = 0;
}

int	animation(t_game *game)
{
	char	*moves;
	char	*coins;

	if (game->i > 1200)
	{
		animate_coin(game);
		animate_goblin(game);
		ft_visualize(game);
		moves = ft_itoa(game->moves);
		coins = ft_itoa(game->coins);
		mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Movimientos: ");
		mlx_string_put(game->mlx, game->win, 120, 10, 0xFFFFFF, moves);
		mlx_string_put(game->mlx, game->win, 10, 30, 0xFFFFFF, "Coins: ");
		mlx_string_put(game->mlx, game->win, 120, 30, 0xFFFFFF, coins);
		free(moves);
		free(coins);
		game->i = 0;
	}
	game->i++;
	return (0);
}
