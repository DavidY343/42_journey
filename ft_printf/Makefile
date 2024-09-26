#Variables

NAME		= libftprintf.a
INCLUDE		= ft_printf.h
LIBFT		= libft
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

#Sources

SRC_FILES	=	ft_printf ft_puthex_c ft_putstr_c 	 \
				ft_putptr_c ft_putnbr_c ft_putchar_c \
				ft_putunbr_c ft_utils


SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re