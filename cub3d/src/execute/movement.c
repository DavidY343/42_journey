/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:59:55 by david             #+#    #+#             */
/*   Updated: 2025/01/18 00:43:12 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	ft_update_pos_if_no_collision(t_mlx *mlx, t_player *p,
	int c_x, int c_y)
{
	double	epsilon;

	epsilon = 2;
	if (mlx->data->fixed_map[(int)((p->y + c_y + epsilon) / WALL_SIZE)]
					[(int)((p->x + c_x + epsilon) / WALL_SIZE)] != '1' &&
		mlx->data->fixed_map[(int)((p->y + c_y + epsilon) / WALL_SIZE)]
					[(int)((p->x + c_x - epsilon) / WALL_SIZE)] != '1' &&
		mlx->data->fixed_map[(int)((p->y + c_y - epsilon) / WALL_SIZE)]
					[(int)((p->x + c_x + epsilon) / WALL_SIZE)] != '1' &&
	mlx->data->fixed_map[(int)((p->y + c_y - epsilon) / WALL_SIZE)]
					[(int)((p->x + c_x - epsilon) / WALL_SIZE)] != '1')
	{
		mlx->player->y += c_y;
		mlx->player->x += c_x;
	}
}

static void	ft_normalize_movement(double *combined_x, double *combined_y)
{
	double	magnitude;

	magnitude = sqrt(*combined_x * *combined_x + *combined_y * *combined_y);
	if (magnitude > 0)
	{
		*combined_x = (*combined_x / magnitude) * PLAYER_SPEED;
		*combined_y = (*combined_y / magnitude) * PLAYER_SPEED;
	}
}

void	ft_move_and_strafe(t_mlx *mlx)
{
	double		combined_x;
	double		combined_y;

	combined_x = (cos(mlx->player->angle) * mlx->player->w_s)
		+ (cos(mlx->player->angle + M_PI_2) * mlx->player->a_d);
	combined_y = (sin(mlx->player->angle) * mlx->player->w_s)
		+ (sin(mlx->player->angle + M_PI_2) * mlx->player->a_d);
	ft_normalize_movement(&combined_x, &combined_y);
	ft_update_pos_if_no_collision(mlx, mlx->player, combined_x, combined_y);
}

void	ft_rotate_player(t_mlx *mlx)
{
	mlx->player->angle += ROTATION_SPEED * mlx->player->rotation;
	if (mlx->player->angle < 0)
		mlx->player->angle += 2 * M_PI;
	else if (mlx->player->angle >= 2 * M_PI)
		mlx->player->angle -= 2 * M_PI;
}
