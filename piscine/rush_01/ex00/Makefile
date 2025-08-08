SRC = node.c utilities.c main.c values_functions.c check_errors.c

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

