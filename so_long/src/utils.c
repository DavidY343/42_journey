/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:57:10 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/20 12:04:59 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/macros.h"

int	count_char(char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

void	finder(int *i, int *j, t_game *game, char c)
{
	int	found;

	found = 0;
	*i = -1;
	while (found == 0 && game->map[++(*i)])
	{
		*j = -1;
		while (found == 0 && game->map[*i][++(*j)])
		{
			if (game->map[*i][*j] == c)
				found = 1;
		}
	}
}

void	change_exit(t_game *game, int i, int j)
{
	if (game->coins == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->oexit, j * WIDTH, i * HEIGHT);
	}
}
