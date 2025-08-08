/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:58:49 by david             #+#    #+#             */
/*   Updated: 2025/01/18 00:52:46 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

float	cast_horizontal(t_mlx *mlx)
{
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = WALL_SIZE;
	x_step = WALL_SIZE / tan(mlx->ray->angle);
	mlx->ray->horiz_y = floor(mlx->player->y / WALL_SIZE) * WALL_SIZE;
	pixel = ft_horizontal_intersection(mlx, &y_step);
	mlx->ray->horiz_x = mlx->player->x
		+ (mlx->ray->horiz_y - mlx->player->y) / tan(mlx->ray->angle);
	if ((unit_circle(mlx->ray->angle, 'y') && x_step > 0)
		|| (!unit_circle(mlx->ray->angle, 'y') && x_step < 0))
		x_step *= -1;
	while (!ft_wall_collision(mlx->ray->horiz_x,
			mlx->ray->horiz_y - pixel, mlx))
	{
		mlx->ray->horiz_x += x_step;
		mlx->ray->horiz_y += y_step;
	}
	return (sqrt(pow(mlx->ray->horiz_x - mlx->player->x, 2)
			+ pow(mlx->ray->horiz_y - mlx->player->y, 2)));
}

float	cast_vertical(t_mlx *mlx)
{
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = WALL_SIZE;
	y_step = WALL_SIZE * tan(mlx->ray->angle);
	mlx->ray->vert_x = floor(mlx->player->x / WALL_SIZE) * WALL_SIZE;
	pixel = ft_vertical_intersection(mlx, &x_step);
	mlx->ray->vert_y = mlx->player->y
		+ (mlx->ray->vert_x - mlx->player->x) * tan(mlx->ray->angle);
	if ((unit_circle(mlx->ray->angle, 'x') && y_step < 0)
		|| (!unit_circle(mlx->ray->angle, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (!ft_wall_collision(mlx->ray->vert_x - pixel, mlx->ray->vert_y, mlx))
	{
		mlx->ray->vert_x += x_step;
		mlx->ray->vert_y += y_step;
	}
	return (sqrt(pow(mlx->ray->vert_x - mlx->player->x, 2)
			+ pow(mlx->ray->vert_y - mlx->player->y, 2)));
}

void	ft_get_distance(t_mlx *mlx)
{
	double	horiz_dist;
	double	vert_dist;

	horiz_dist = cast_horizontal(mlx);
	vert_dist = cast_vertical(mlx);
	if (horiz_dist < vert_dist)
	{
		mlx->ray->distance = horiz_dist;
		mlx->ray->side = 0;
	}
	else
	{
		mlx->ray->distance = vert_dist;
		mlx->ray->side = 1;
	}
}

void	ft_raycast(t_mlx *mlx)
{
	int		ray;

	ray = 0;
	while (ray < S_W)
	{
		mlx->ray->side = 1;
		mlx->ray->angle = mlx->player->angle
			+ atan(((2.0 * ray / S_W) - 1) * tan(mlx->player->fov_rd / 2));
		mlx->ray->angle = normalize_angle(mlx->ray->angle);
		ft_get_distance(mlx);
		mlx->ray->index = ray;
		draw_ray_column(mlx);
		mlx->ray->angle = normalize_angle(mlx->ray->angle);
		ray++;
	}
}
