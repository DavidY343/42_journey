##########################################
# PROBAR ESTO ############################
#.SILENT:clean to silence an instruction #
##########################################

######################
#     Variables      #
######################

LIBFT_PATH = ./libft
MLX_PATH = ./MLX42

MLX_BUILD_DIR = $(MLX_PATH)/build
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MLX_LIB = $(MLX_BUILD_DIR)/libmlx42.a

LIBS = $(LIBFT_LIB)/libft.a $(LIBMLX_LIB)/libmlx42.a

MLX_FLAGS = $(MLX_LIB) -ldl -lglfw -pthread -lm
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D



######################
#      SOURCES       #
######################

SRCS_RAYCAST		=	raycast.c raycast_utils.c render.c render_utils.c
SRCS_TEXTURE		=	load_texture.c texture.c texture_utils.c texture_s.c texture_s_aux.c
SRCS_FREE			=	free_parser_handler.c free_mlx_handler.c
SRCS_PARSER			=	parser.c check_map.c get_map_data.c read_file.c parser_utils.c
SRCS_EXECUTE		=	execute.c mlx_hook_handler.c movement.c
SRCS_CUB3D			=	$(addprefix ./execute/, $(SRCS_EXECUTE)) $(addprefix ./parser/, $(SRCS_PARSER)) $(addprefix ./free/, $(SRCS_FREE)) $(addprefix ./raycast/, $(SRCS_RAYCAST)) $(addprefix ./texture/, $(SRCS_TEXTURE))  main.c
DIR_CUB3D			=	$(addprefix ./src/, $(SRCS_CUB3D))
OBJS				= 	$(DIR_CUB3D:.c=.o)

######################
#       COLORS       #
######################

RED					=	\033[91m
YELLOW				=	\033[93m
GREEN				=	\033[92m
NO_COLOR			=	\033[0m
BLUE				= 	\033[1;38;5;27m

######################
#    INSTRUCTIONS    #
######################

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<
		@echo "$(BLUE)CUB3D Compiling:$(END) $(notdir $<)"
 
$(NAME): $(OBJS)
	@echo "$(YELLOW)[COMPILING CUB3D]$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(GREEN)[COMPILED CUB3D]$(NO_COLOR)"
 
$(MLX_LIB):
	@echo "$(YELLOW)[CONFIGURING MLX WITH CMAKE]$(NO_COLOR)"
	@cmake -B $(MLX_BUILD_DIR) -S $(MLX_PATH) > /dev/null 2>&1
	@echo "$(YELLOW)[BUILDING MLX LIBRARY]$(NO_COLOR)"
	@cmake --build $(MLX_BUILD_DIR) -j4 > /dev/null 2>&1
	@echo "$(GREEN)[MLX LIBRARY COMPILED SUCCESSFULLY]$(NO_COLOR)"

#> /dev/null
$(LIBFT_LIB):
	@echo "$(YELLOW)[COMPILING LIBFT]$(NO_COLOR)"
	@make -s -C $(LIBFT_PATH)
	@echo "$(GREEN)[COMPILED LIBFT]$(NO_COLOR)"

norminette:
	@echo "$(YELLOW)[CHECKING NORMINETTE]$(NO_COLOR)"
	@norminette ./src/
	@norminette ./headers/

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@echo "$(RED)[CUB3D DELETED]$(NO_COLOR)"

clean:	
	@echo "$(RED)[LIBFT DELETED]$(NO_COLOR)"
	@make -s -C $(LIBFT_PATH) clean
	@echo "$(RED)[MLX DELETED]$(NO_COLOR)"
	@rm -rf $(MLX_BUILD_DIR)
	@echo "$(RED)[OBJS DELETED]$(NO_COLOR)"
	@$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re