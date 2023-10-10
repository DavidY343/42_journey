#Variables

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

#SOURCES
SRCS_PIPEX	=	pipex.c

DIR_PIPEX	=	$(addprefix ./src/, $(SRCS_PIPEX))

OBJS			= 	$(DIR_PIPEX:.c=.o)

#INSTRUCTIONS

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DIR_PIPEX) -o $(NAME)

#$(LIBFT):
#	make -C $(LIBFT_PATH) all

clean:	
#	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
#	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re