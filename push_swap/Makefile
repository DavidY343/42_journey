#Variables

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

#SOURCES
SRCS_PUSH_SWAP	=	input_handler.c push_op.c push_swap.c reverse_op.c rotate_op.c swap_op.c	\
					find_mid.c sort_one.c sort_two.c sort_utils.c stack_utils.c free_handler.c peek_op.c

DIR_PUSH_SWAP	=	$(addprefix ./src/, $(SRCS_PUSH_SWAP))

OBJS			= 	$(DIR_PUSH_SWAP:.c=.o)

#INSTRUCTIONS

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(DIR_PUSH_SWAP) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:	
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re