/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:56:25 by david             #+#    #+#             */
/*   Updated: 2025/01/18 17:35:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	init_player(t_mlx *mlx)
{
	char	c;

	mlx->player->w_s = 0;
	mlx->player->a_d = 0;
	mlx->player->rotation = 0;
	c = mlx->data->fixed_map[mlx->data->pos_y][mlx->data->pos_x];
	if (c == 'N')
		mlx->player->angle = 3 * M_PI_2;
	if (c == 'S')
		mlx->player->angle = M_PI_2;
	if (c == 'E')
		mlx->player->angle = 0;
	if (c == 'W')
		mlx->player->angle = M_PI;
	mlx->player->x = (mlx->data->pos_x * WALL_SIZE) + WALL_SIZE / 2;
	mlx->player->y = (mlx->data->pos_y * WALL_SIZE) + WALL_SIZE / 2;
	mlx->player->fov_rd = (FOV * M_PI / 180);
}

static void	init_ray(t_mlx *mlx)
{
	mlx->ray->index = 0;
	mlx->ray->angle = 0;
	mlx->ray->horiz_x = 0;
	mlx->ray->horiz_y = 0;
	mlx->ray->vert_x = 0;
	mlx->ray->vert_y = 0;
	mlx->ray->distance = 0;
	mlx->ray->side = 0;
}

static void	execute_aux(t_mlx *mlx)
{
	init_player(mlx);
	mlx_key_hook(mlx->mlx_ptr, &ft_key_action, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &cub3d_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	ft_exit(mlx);
}

void	execute(t_parse *data)
{
	t_mlx	mlx;

	mlx.data = data;
	mlx.mlx_ptr = mlx_init(S_W, S_H, "cub3D", false);
	if (!mlx.mlx_ptr)
		ft_exit(&mlx);
	mlx.img = mlx_new_image(mlx.mlx_ptr, S_W, S_H);
	if (!mlx.img)
		ft_exit(&mlx);
	mlx.player = calloc(1, sizeof(t_player));
	if (!mlx.player)
		ft_exit(&mlx);
	mlx.ray = calloc(1, sizeof(t_raycast));
	if (!mlx.ray)
		ft_exit(&mlx);
	mlx.tex = calloc(1, sizeof(t_texture_mlx));
	if (!mlx.tex)
		ft_exit(&mlx);
	init_ray(&mlx);
	if (!ft_load_textures(&mlx, data->texture_s))
		ft_exit(&mlx);
	execute_aux(&mlx);
}
