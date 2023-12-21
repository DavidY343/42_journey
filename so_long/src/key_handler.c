/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:26:06 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/21 14:00:23 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

void	move_w(t_game *game, int i, int j)
{
	game->img->pstart = game->img->pback;
	if (game->map[i - 1][j] == 'E' && game->coins == 0)
		free_mlx(game);
	if (game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'E')
	{
		if (game->map[i - 1][j] == 'C')
			game->coins--;
		game->moves++;
		game->map[i - 1][j] = 'P';
		game->map[i][j] = '0';
		game->img->pstart = game->img->pback;
		ft_printf("Movimiento: %d\n", game->moves);
	}
	ft_visualize(game);
}

void	move_s(t_game *game, int i, int j)
{
	game->img->pstart = game->img->pfront;
	if (game->map[i + 1][j] == 'E' && game->coins == 0)
		free_mlx(game);
	if (game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'E')
	{
		if (game->map[i + 1][j] == 'C')
			game->coins--;
		game->moves++;
		game->map[i + 1][j] = 'P';
		game->map[i][j] = '0';
		ft_printf("Movimiento: %d\n", game->moves);
	}
	ft_visualize(game);
}

void	move_d(t_game *game, int i, int j)
{
	game->img->pstart = game->img->pright;
	if (game->map[i][j + 1] == 'E' && game->coins == 0)
		free_mlx(game);
	if (game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'E')
	{
		if (game->map[i][j + 1] == 'C')
			game->coins--;
		game->moves++;
		game->map[i][j + 1] = 'P';
		game->map[i][j] = '0';
		ft_printf("Movimiento: %d\n", game->moves);
	}
	ft_visualize(game);
}

void	move_a(t_game *game, int i, int j)
{
	game->img->pstart = game->img->pleft;
	if (game->map[i][j - 1] == 'E' && game->coins == 0)
		free_mlx(game);
	if (game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'E')
	{
		if (game->map[i][j - 1] == 'C')
			game->coins--;
		game->moves++;
		game->map[i][j - 1] = 'P';
		game->map[i][j] = '0';
		ft_printf("Movimiento: %d\n", game->moves);
	}
	ft_visualize(game);
}

int	key_handler(int key, t_game *game)
{
	int	i;
	int	j;

	finder(&i, &j, game, 'P');
	if (key == DESTROY)
		free_mlx(game);
	else if (key == UP)
		move_w(game, i, j);
	else if (key == RIGHT)
		move_d(game, i, j);
	else if (key == LEFT)
		move_a(game, i, j);
	else if (key == DOWN)
		move_s(game, i, j);
	change_exit(game);
	return (0);
}
