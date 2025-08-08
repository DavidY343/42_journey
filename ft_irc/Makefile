# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 13:30:00 by david             #+#    #+#              #
#    Updated: 2025/06/14 13:25:00 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################
#     Variables      #
######################

NAME        = ircserv
CXX         = c++
RM          = rm -f
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -Iincludes

######################
#      Sources       #
######################

SRC_DIR     = src
INC_DIR     = includes

SRC_FILES   = $(wildcard $(SRC_DIR)/*.cpp) \
              $(wildcard $(SRC_DIR)/network/*.cpp) \
              $(wildcard $(SRC_DIR)/commands/*.cpp)

OBJ_FILES   = $(SRC_FILES:.cpp=.o)

######################
#       Colors       #
######################

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
NC          = \033[0m

######################
#     Targets        #
######################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)[Linking executable]$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)[Build complete]$(NC)"

%.o: %.cpp
	@echo "$(YELLOW)[Compiling] $<$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(RED)[Objects deleted]$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[Executable deleted]$(NC)"

re: fclean all

.PHONY: all clean fclean re
