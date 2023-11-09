/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:07:00 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:15:22 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <string.h>
# include <fcntl.h>
# include <math.h> 
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"

typedef struct s_data
{
	char	**map;
	int		width;
	int		height;
	int		coins;
	int		c_coins;
	int		exit;
}	t_data;

//main.c 
int	flood_fill(int x, int y, t_data *data, char **map);
// error_handler.c 
void	msg_error(char *text);
void	msg_error_param(char *text, char *param);
void	msg_error_map(char *text, char **map);

//input_handler.c
void	check_inputs(int argc, char **argv, t_data *data);

//utils.c
int		count_char(char *str, char c);

//free_handler.c
void	free_map(char **map);

#endif