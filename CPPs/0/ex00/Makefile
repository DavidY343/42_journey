# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 12:29:08 by david             #+#    #+#              #
#    Updated: 2024/09/26 13:25:58 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################
#     Variables      #
######################

CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

######################
#      SOURCES       #
######################

NAMES	= megaphone
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
		@echo "$(YELLOW)[COMPILING EX00]$(NO_COLOR)"
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "$(GREEN)[COMPILED EX00]$(NO_COLOR)"


fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)[DELETED]$(NO_COLOR)"

clean:
		@$(RM) $(OBJ) $(OBJS_BONUS)

re: fclean all