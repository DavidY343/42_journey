/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:01:26 by david             #+#    #+#             */
/*   Updated: 2025/01/18 00:54:49 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	ft_render_ceiling(t_mlx *mlx, int draw_start)
{
	int	i;
	int	c;

	c = ft_get_rgba(ft_atoi(mlx->data->cc[0]), ft_atoi(mlx->data->cc[1]),
			ft_atoi(mlx->data->cc[2]), 255);
	i = 0;
	while (i < draw_start)
	{
		if (mlx->ray->index >= 0 && mlx->ray->index < S_W
			&& i >= 0 && i < S_H)
			mlx_put_pixel(mlx->img, mlx->ray->index, i, c);
		i++;
	}
}

static void	ft_render_floor(t_mlx *mlx, int draw_end)
{
	int	c;

	c = ft_get_rgba(ft_atoi(mlx->data->ff[0]), ft_atoi(mlx->data->ff[1]),
			ft_atoi(mlx->data->ff[2]), 255);
	while (draw_end < S_H)
	{
		if (mlx->ray->index >= 0 && mlx->ray->index < S_W
			&& draw_end >= 0 && draw_end < S_H)
			mlx_put_pixel(mlx->img, mlx->ray->index, draw_end, c);
		draw_end++;
	}
}

void	ft_render_wall(t_mlx *mlx, int draw_start, int draw_end, double wall_h)
{
	double			texture_x;
	double			texture_y;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = ft_get_texture(mlx, mlx->ray->side);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	texture_x = ft_get_texture_x(texture, mlx);
	texture_y = (draw_start - (S_H / 2) + (wall_h / 2)) * factor;
	if (texture_y < 0)
		texture_y = 0;
	while (draw_start < draw_end)
	{
		if (mlx->ray->index >= 0 && mlx->ray->index < S_W
			&& draw_start >= 0 && draw_start < S_H)
		{
			mlx_put_pixel(mlx->img, mlx->ray->index, draw_start,
				ft_reverse_bytes(arr[(int)texture_y
					* texture->width + (int)texture_x]));
		}
		texture_y += factor;
		draw_start++;
	}
}

void	draw_ray_column(t_mlx *mlx)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	mlx->ray->distance *= cos(normalize_angle(mlx->ray->angle
				- mlx->player->angle));
	line_height = (WALL_SIZE / mlx->ray->distance) * ((S_W / 2)
			/ tan(mlx->player->fov_rd / 2));
	draw_start = -line_height / 2 + S_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + S_H / 2;
	if (draw_end >= S_H)
		draw_end = S_H - 1;
	ft_render_wall(mlx, draw_start, draw_end, line_height);
	ft_render_floor(mlx, draw_end);
	ft_render_ceiling(mlx, draw_start);
}
