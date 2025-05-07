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
NAME = so_long


######################
#      SOURCES       #
######################


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

all: up

up:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build -d

down:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env down

re: down up

clean:
	docker system prune -af --volumes

fclean: down clean

.PHONY: all up down re clean fclean