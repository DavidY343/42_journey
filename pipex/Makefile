#Variables

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

NAME = pipex

#SOURCES
SRCS_PIPEX			=	pipex.c pipex_utils.c
SRCS_PIPEX_BONUS	=	pipex_bonus.c pipex_utils_bonus.c
DIR_PIPEX			=	$(addprefix ./src/, $(SRCS_PIPEX))
DIR_PIPEX_BONUS		=	$(addprefix ./src_bonus/, $(SRCS_PIPEX_BONUS))
OBJS				= 	$(DIR_PIPEX:.c=.o)
OBJS_BONUS			= 	$(DIR_PIPEX_BONUS:.c=.o)
CACHE				=	.cache
#INSTRUCTIONS

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(CACHE) : $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME) $(LIBFT)
	touch $(CACHE)
bonus: $(CACHE)

clean:	
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(CACHE)

re: fclean all

.PHONY: all clean fclean re