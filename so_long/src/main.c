/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:11:24 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:16:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/so_long.h"

int	flood_fill(int x, int y, t_data *data, char **map)
{
	if (x < 0 || x >= (data->height - 1) || y < 0 || y >= (data->width - 1))
		return (0);
	if (map[x][y] == 'E')
		data->exit = 1;
	if (data->exit == 1 && data->c_coins == data->coins)
		return (1);
	else if (map[x][y] == '0' || map[x][y] == 'P'
			|| map[x][y] == 'C')
	{
		if (map[x][y] == 'C')
			data->c_coins++;
		map[x][y] = '.';
		if (flood_fill(x + 1, y, data, map) || flood_fill(x - 1, y, data, map)
			|| flood_fill(x, y + 1, data, map)
			|| flood_fill(x, y - 1, data, map))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_inputs(argc, argv, &data);
	return (0);
}
