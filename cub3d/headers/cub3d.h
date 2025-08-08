/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:17:00 by ezafra-r          #+#    #+#             */
/*   Updated: 2025/01/23 14:24:53 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*═════════════════════════ [  INCLUDES  ] ═══════════════════════════════*/

// personal libs
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
// global libs
# include <fcntl.h>      // Para open
# include <unistd.h>     // Para close, read, write
# include <sys/time.h>   // Para gettimeofday
# include <stdio.h>      // Para printf, perror
# include <stdlib.h>     // Para malloc, free, exit
# include <string.h>     // Para strerror
# include <math.h>       // Para funciones matemáticas como sin, cos, sqrt, pow

/*═══════════════════════════ [  MACROS  ] ═══════════════════════════════════*/

// MLX - GAME

# define S_W 2560             // screen width
# define S_H 1440             // screen height
# define WALL_SIZE 64         // wall size
# define FOV 60               // field of view
# define ROTATION_SPEED 0.06 // rotation speed
# define PLAYER_SPEED 8       // player speed

/*══════════════════════════ [  STRUCTS  ] ═══════════════════════════════════*/

typedef struct s_texture_mlx
{
	mlx_texture_t		*no;
	mlx_texture_t		*so;
	mlx_texture_t		*we;
	mlx_texture_t		*ea;
}						t_texture_mlx;

typedef struct s_texture
{
	char				*name;
	char				*value;
	struct s_texture	*next;
}						t_texture;

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	float	fov_rd;
	int		rotation;
	int		a_d;
	int		w_s;
}						t_player;

typedef struct s_raycast
{
	int					index;
	double				angle;
	double				horiz_x;
	double				horiz_y;
	double				vert_x;
	double				vert_y;
	double				distance;
	int					side;
}						t_raycast;

typedef struct s_parse
{
	int			pos_x;
	int			pos_y;
	int			width;
	int			height;
	int			fd;
	int			count;
	char		*line;
	char		*texture;
	char		**texture_2d;
	char		*map;
	char		**map_2d;
	char		**fixed_map;
	char		**cc;
	char		**ff;
	t_texture	*texture_s;
}						t_parse;

typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_ptr;
	t_raycast		*ray;
	t_player		*player;
	t_texture_mlx	*tex;
	t_parse			*data;
}				t_mlx;

/*═════════════════════════ [  FUNCTIONS  ] ══════════════════════════════════*/
/*-------------------------- [  parsing  ] -----------------------------------*/

// PARSER

int				parser(int ac, char **av, t_parse *map);

//read_file.c
int				read_file(char *argv, t_parse *map);

//texture.c
void			get_texture(t_parse *map);
int				check_textures(t_parse *map);
int				check_colors(t_parse *map);

//texture_utils
int				check_floor_ceiling(char *temp);

//texture_s
int				fill_texture_s(t_parse **map);

//texture_s_aux

int				fill_color(t_parse **map);

//utils.c
int				check_space(int c);
int				intlen(int number);
int				longest_line(char **map);
int				ft_len_arr(char **array);
size_t			ft_len(const char *str);

//free_handler.c
void			free_temp(t_parse *map);
void			free_temp_2d(t_parse *map);
void			free_double(char **arr);
void			free_map(t_parse *map);

//check_map.c
int				check_close_map(t_parse *map);

//get_map_data.c
int				map_data(t_parse *map);
/*═════════════════════════ [  execute  ] ═════════════════════════*/

// execute.c
void			execute(t_parse *data);

// texture_handler.c
int				ft_load_textures(t_mlx *mlx, t_texture *t_list);

// free_handler.c
void			ft_exit(t_mlx *mlx);

// mlx_hook_handler.c
void			ft_key_action(mlx_key_data_t keydata, void *game);
void			cub3d_hook(void *game);

// movement.c
void			ft_move_and_strafe(t_mlx *mlx);
void			ft_rotate_player(t_mlx *mlx);

// raycast.c
void			ft_raycast(t_mlx *mlx);

// render.c
void			draw_ray_column(t_mlx *mlx);

//render_utils.c
double			ft_get_texture_x(mlx_texture_t *texture, t_mlx *mlx);
mlx_texture_t	*ft_get_texture(t_mlx *mlx, int side);
int				ft_reverse_bytes(int c);
int				ft_get_rgba(int r, int g, int b, int a);

//raycast_utils.c
float			normalize_angle(float angle);
int				unit_circle(float angle, char c);
int				ft_vertical_intersection(t_mlx *mlx, float *step);
int				ft_horizontal_intersection(t_mlx *mlx, float *step);
int				ft_wall_collision(float x, float y, t_mlx *mlx);

#endif