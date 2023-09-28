

#Variables

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

#Sources
SRC_libft	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_printf	=	ft_printf.c ft_puthex_c.c ft_putstr_c.c 	 \
				ft_putptr_c.c ft_putnbr_c.c ft_putchar_c.c \
				ft_putunbr_c.c ft_utils.c

SRC_gnl		=	get_next_line_utils.c get_next_line.c

DIR_printf	= 	$(addprefix ft_printf/, $(SRC_printf))
DIR_gnl		= 	$(addprefix get_next_line/, $(SRC_gnl))

OBJ_printf	=	$(DIR_printf:.c=.o)
OBJ_gnl		=	$(DIR_gnl:.c=.o)
OBJ_libft	= 	$(SRC_libft:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ_printf) $(OBJ_gnl) $(OBJ_libft)
			$(AR) $(NAME) $^
	
clean:
			$(RM) $(OBJ_printf) $(OBJ_gnl) $(OBJ_libft)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

--------------------------------------------------
SRCS = 	$(addprefix srcs/commands/,				\
		push.c rev_rotate.c rotate.c swap.c)			\
	$(addprefix srcs/stack_utils/,				\
		add_back.c find_last.c new_node.c		\
		search_first.c search_last.c add_front.c	\
		find_index.c free_node.c)						\
	$(addprefix srcs/algorithm/,				\
		check.c init.c main.c sort_three.c sort.c	\
		sort_five.c sort_range.c)					

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)

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