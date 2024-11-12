# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 19:51:48 by david             #+#    #+#              #
#    Updated: 2024/11/12 21:05:11 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################
#     Variables      #
######################

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fragtrap

######################
#      SOURCES       #
######################

NAMES	= main ClapTrap ScavTrap FragTrap
SRC = $(addsuffix .cpp, $(NAMES))
OBJ = $(SRC:.cpp=.o)

######################
#       COLORS       #
######################

RED                             =       \033[91m
YELLOW                          =       \033[93m
GREEN                           =       \033[92m
NO_COLOR                        =       \033[0m

######################
#    INSTRUCTIONS    #
######################

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(YELLOW)[COMPILING EX02]$(NO_COLOR)"
		@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "$(GREEN)[COMPILED EX02]$(NO_COLOR)"


$(OBJ): $(SRC)
		@echo "$(YELLOW)[COMPILING OBJS]$(NO_COLOR)"
		@$(CC) $(CPPFLAGS) -c $(SRC)
		@echo "$(GREEN)[COMPILED OBJS]$(NO_COLOR)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)[DELETED]$(NO_COLOR)"

clean:
		@$(RM) $(OBJ) $(OBJS_BONUS)

re: fclean all