##########################################
# PROBAR ESTO ############################
#.SILENT:clean to silence an instruction #
##########################################


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
	sudo docker-compose -f docker-compose.yaml --env-file .env up --build -d

down:
	sudo docker-compose -f docker-compose.yaml --env-file .env down

re: down up

clean:
	docker system prune -af --volumes

fclean: down clean

reclean: fclean up

.PHONY: all up down re clean fclean