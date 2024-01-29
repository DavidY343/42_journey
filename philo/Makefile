##########################################
# PROBAR ESTO ############################
#.SILENT:clean to silence an instruction #
##########################################

######################
#     Variables      #
######################

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = philo


######################
#      SOURCES       #
######################

SRCS_PHILO			=	main.c
DIR_PHILO			=	$(addprefix ./src/, $(SRCS_PHILO))
OBJS				= 	$(DIR_PHILO:.c=.o)

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

all: $(NAME)
 
$(NAME): $(OBJS)
	@echo "$(YELLOW)[COMPILING PHILO]$(NO_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@echo "$(GREEN)[COMPILED PHILO]$(NO_COLOR)"

norminette:
	@echo "$(YELLOW)[CHECKING NORMINETTE]$(NO_COLOR)"
	@norminette ./src/
	@norminette ./headers/

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(CACHE)
	@echo "$(RED)[DELETED]$(NO_COLOR)"

clean:	
	@make -s -C $(LIBFT_PATH) clean¡
	@$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re