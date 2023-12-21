##########################################
# PROBAR ESTO ############################
#.SILENT:clean to silence an instruction #
##########################################

######################
#     Variables      #
######################

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = so_long


MLX_INCLUDES = -I/opt/X11/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

######################
#      SOURCES       #
######################

SRCS_SO_LONG		=	main.c error_handler.c input_handler.c utils.c free_handler.c load_image.c put_image.c key_handler.c
SRCS_SO_LONG_BONUS	=	main_bonus.c error_handler_bonus.c input_handler_bonus.c utils_bonus.c free_handler_bonus.c image_handler_bonus.c key_handler_bonus.c
DIR_SO_LONG			=	$(addprefix ./src/, $(SRCS_SO_LONG))
DIR_SO_LONG_BONUS	=	$(addprefix ./src_bonus/, $(SRCS_SO_LONG_BONUS))
OBJS				= 	$(DIR_SO_LONG:.c=.o)
OBJS_BONUS			= 	$(DIR_SO_LONG_BONUS:.c=.o)
CACHE				=	.cache

######################
#       COLORS       #
######################

RED					=	\033[91m
YELLOW				=	\033[93m
GREEN				=	\033[92m
NO_COLOR			=	\033[0m

######################
#    INSTRUCTIONS    #
######################

all: $(MLX_LIB) $(LIBFT) $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< $(MLX_MLX_INCLUDES)
 
$(NAME): $(OBJS)
	@echo "$(YELLOW)[COMPILING SO_LONG]$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(GREEN)[COMPILED SO_LONG]$(NO_COLOR)"
 
$(MLX_LIB):
	@echo "$(YELLOW)[COMPILING MLX]$(NO_COLOR)"
	@make -C $(MLX_DIR) all > /dev/null 2>&1
	@echo "$(GREEN)[COMPILED MLX]$(NO_COLOR)"
#> /dev/null
$(LIBFT):
	@echo "$(YELLOW)[COMPILING LIBFT]$(NO_COLOR)"
	@make -s -C $(LIBFT_PATH) all
	@echo "$(GREEN)[COMPILED LIBFT]$(NO_COLOR)"


$(CACHE) : $(OBJS_BONUS) $(LIBFT)
	@echo "$(YELLOW)[COMPILING SO_LONG_BONUS]$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@touch $(CACHE)
	@echo "$(GREEN)[COMPILED SO_LONG_BONUS]$(NO_COLOR)"

bonus: $(MLX_LIB) $(LIBFT) $(CACHE)

norminette:
	@echo "$(YELLOW)[CHECKING NORMINETTE]$(NO_COLOR)"
	@norminette ./src/
	@norminette ./src_bonus/
	@norminette ./headers/

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(CACHE)
	@echo "$(RED)[DELETED]$(NO_COLOR)"

clean:	
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re