/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:39:42 by david             #+#    #+#             */
/*   Updated: 2025/01/18 17:53:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

int	ft_reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

double	ft_get_texture_x(mlx_texture_t *texture, t_mlx *mlx)
{
	double	texture_x;
	double	position;

	if (mlx->ray->side == 0)
		position = mlx->ray->horiz_x;
	else
		position = mlx->ray->vert_y;
	texture_x = fmod(position, WALL_SIZE) * (texture->width / WALL_SIZE);
	return (texture_x);
}

mlx_texture_t	*ft_get_texture(t_mlx *mlx, int side)
{
	mlx->ray->angle = normalize_angle(mlx->ray->angle);
	if (side == 1)
	{
		if (mlx->ray->angle > M_PI / 2 && mlx->ray->angle < 3 * (M_PI / 2))
			return (mlx->tex->we);
		else
			return (mlx->tex->ea);
	}
	else
	{
		if (mlx->ray->angle > 0 && mlx->ray->angle < M_PI)
			return (mlx->tex->so);
		else
			return (mlx->tex->no);
	}
}
