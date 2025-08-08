/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:18:26 by david             #+#    #+#             */
/*   Updated: 2025/01/18 17:14:18 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	ft_key_release(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
			mlx->player->w_s = 0;
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
			mlx->player->a_d = 0;
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
			mlx->player->rotation = 0;
	}
}

void	ft_key_action(mlx_key_data_t keydata, void *game)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)game;
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		printf("Exited by ESC key\n");
		ft_exit(mlx);
	}
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			mlx->player->w_s = 1;
		if (keydata.key == MLX_KEY_S)
			mlx->player->w_s = -1;
		if (keydata.key == MLX_KEY_A)
			mlx->player->a_d = -1;
		if (keydata.key == MLX_KEY_D)
			mlx->player->a_d = 1;
		if (keydata.key == MLX_KEY_LEFT)
			mlx->player->rotation = -1;
		if (keydata.key == MLX_KEY_RIGHT)
			mlx->player->rotation = 1;
	}
	ft_key_release(keydata, mlx);
}

void	cub3d_hook(void *game)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)game;
	mlx_delete_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, S_W, S_H);
	if (mlx->player->w_s || mlx->player->a_d)
		ft_move_and_strafe(mlx);
	if (mlx->player->rotation)
		ft_rotate_player(mlx);
	ft_raycast(mlx);
	mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}
