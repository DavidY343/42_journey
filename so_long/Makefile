#Variables

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
INCLUDES = -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
#ifeq ($(shell uname), Linux)
#	INCLUDES = -I/usr/include -Imlx
#else
#	INCLUDES = -I/opt/X11/include -Imlx
#endif
 
#MLX_DIR = ./mlx
#MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
#ifeq ($(shell uname), Linux)
#	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
#else
#	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
#endif
#.SILENT:clean to silence an instruction be sure to check it out

#SOURCES
SRCS_SO_LONG		=	main.c 
SRCS_SO_LONG_BONUS	=	...
DIR_SO_LONG			=	$(addprefix ./src/, $(SRCS_SO_LONG))
DIR_SO_LONG_BONUS	=	$(addprefix ./src_bonus/, $(SRCS_SO_LONG_BONUS))
OBJS				= 	$(DIR_SO_LONG:.c=.o)
OBJS_BONUS			= 	$(DIR_SO_LONG_BONUS:.c=.o)
CACHE				=	.cache

#INSTRUCTIONS

all: $(MLX_LIB) $(NAME) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
 
$(MLX_LIB):
	@make -C $(MLX_DIR) all > /dev/null 2>&1

$(LIBFT):
	@make -C $(LIBFT_PATH) all > /dev/null

$(CACHE) : $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT)
	touch $(CACHE)

bonus: $(CACHE)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(CACHE)

clean:	
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re