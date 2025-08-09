/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:57:16 by david             #+#    #+#             */
/*   Updated: 2025/01/18 17:25:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_wall_collision(float x, float y, t_mlx *mlx)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0 || x >= mlx->data->width * WALL_SIZE
		|| y >= mlx->data->height * WALL_SIZE)
		return (1);
	map_x = floor(x / WALL_SIZE);
	map_y = floor(y / WALL_SIZE);
	if (mlx->data->fixed_map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	ft_horizontal_intersection(t_mlx *mlx, float *step)
{
	if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
	{
		mlx->ray->horiz_y += WALL_SIZE;
		return (-1);
	}
	*step *= -1;
	return (1);
}

int	ft_vertical_intersection(t_mlx *mlx, float *step)
{
	if (!(mlx->ray->angle > M_PI / 2 && mlx->ray->angle < 3 * M_PI / 2))
	{
		mlx->ray->vert_x += WALL_SIZE;
		return (-1);
	}
	*step *= -1;
	return (1);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}
