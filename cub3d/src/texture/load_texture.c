/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <jonjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:49:05 by david             #+#    #+#             */
/*   Updated: 2025/01/18 01:04:18 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	ft_load_textures_aux(t_texture	*tmp, t_mlx *mlx)
{
	if (!ft_strncmp(tmp->name, "NO", 2))
	{
		mlx->tex->no = mlx_load_png(tmp->value);
		if (!mlx->tex->no)
			return (0);
	}
	else if (!ft_strncmp(tmp->name, "SO", 2))
	{
		mlx->tex->so = mlx_load_png(tmp->value);
		if (!mlx->tex->so)
			return (0);
	}
	else if (!ft_strncmp(tmp->name, "WE", 2))
	{
		mlx->tex->we = mlx_load_png(tmp->value);
		if (!mlx->tex->we)
			return (0);
	}
	else if (!ft_strncmp(tmp->name, "EA", 2))
	{
		mlx->tex->ea = mlx_load_png(tmp->value);
		if (!mlx->tex->ea)
			return (0);
	}
	return (1);
}

int	ft_load_textures(t_mlx *mlx, t_texture *t_list)
{
	t_texture	*tmp;

	tmp = t_list;
	while (tmp)
	{
		if (ft_load_textures_aux(tmp, mlx) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
