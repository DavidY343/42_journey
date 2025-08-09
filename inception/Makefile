######################
#      SOURCES       #
######################

# docker exec -it mariadb mysql -u root -p

# USE wordpress;
# SELECT * FROM wp_comments;

######################
#    INSTRUCTIONS    #
######################

all: up

prepare_data_dirs:
	sudo mkdir -p /home/david/data/mariadb/
	sudo mkdir -p /home/david/data/wordpress/

up: prepare_data_dirs
	sudo docker-compose -f srcs/docker-compose.yaml --env-file srcs/.env up --build -d

down:
	sudo docker-compose -f srcs/docker-compose.yaml --env-file srcs/.env down

re: down up

clean:
	sudo docker system prune -af --volumes

fclean: down clean
	sudo rm -rf /home/david/data/wordpress/*
	sudo rm -rf /home/david/data/mariadb/*

reclean: fclean up

.PHONY: all up down re clean fclean