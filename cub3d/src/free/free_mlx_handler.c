/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:33:41 by david             #+#    #+#             */
/*   Updated: 2025/01/18 16:25:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	ft_delete_tex(t_texture_mlx *tex)
{
	if (tex->no)
	{
		mlx_delete_texture(tex->no);
		tex->no = NULL;
	}
	if (tex->so)
	{
		mlx_delete_texture(tex->so);
		tex->so = NULL;
	}
	if (tex->we)
	{
		mlx_delete_texture(tex->we);
		tex->we = NULL;
	}
	if (tex->ea)
	{
		mlx_delete_texture(tex->ea);
		tex->ea = NULL;
	}
	free(tex);
}

static void	ft_exit_aux(t_mlx *mlx)
{
	if (mlx->mlx_ptr)
	{
		mlx_close_window(mlx->mlx_ptr);
		mlx_terminate(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	if (mlx->data)
	{
		free_map(mlx->data);
		mlx->data = NULL;
	}
}

void	ft_exit(t_mlx *mlx)
{
	if (mlx->img)
	{
		mlx_delete_image(mlx->mlx_ptr, mlx->img);
		mlx->img = NULL;
	}
	if (mlx->player)
	{
		free(mlx->player);
		mlx->player = NULL;
	}
	if (mlx->ray)
	{
		free(mlx->ray);
		mlx->ray = NULL;
	}
	if (mlx->tex)
	{
		ft_delete_tex(mlx->tex);
		mlx->tex = NULL;
	}
	ft_exit_aux(mlx);
	exit(0);
}
