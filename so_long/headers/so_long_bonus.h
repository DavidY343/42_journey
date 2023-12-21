/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:07:00 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/12/21 14:55:07 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
//struct for the image
typedef struct s_img
{
	void	*wwall;
	void	*wfloor;
	void	*pfront;
	void	*pback;
	void	*pleft;
	void	*pright;
	void	*cexit;
	void	*oexit;
	void	*coin;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*coin7;
	void	*coin8;
	void	*pstart;
	void	*gstart;
	void	*gfront1;
	void	*gfront2;
	void	*gfront3;
	int		width;
	int		height;
}	t_img;
//struct to init the params
typedef struct s_prs
{
	char	**map;
	int		width;
	int		height;
	int		coins;
	int		c_coins;
	int		exit;
}	t_prs;

//struct to play the game
typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		coins;
	int		moves;
	int		i;
	int		controlc;
	int		controlg;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_game;

//main.c 
int		flood_fill(int x, int y, t_prs *prs, char **map);

// error_handler.c 
void	msg_error(char *text);
void	msg_error_param(char *text, char *param);
void	msg_error_map(char *text, char **map);

//input_handler.c
void	check_inputs(int argc, char **argv, t_prs *prs);

//utils.c
int		count_char(char *str, char c);
void	change_exit(t_game *game);
void	finder(int *i, int *j, t_game *game, char c);

//free_handler.c
void	free_map(char **map);
int		free_mlx(t_game *game);

//image_handler.c
void	init_image(t_game *game);
void	ft_visualize(t_game *game);

//key_handler.c
int		key_handler(int key, t_game *game);

//animation.c
int		animation(t_game *game);
#endif