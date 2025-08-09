# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyanez-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 13:37:25 by dyanez-m          #+#    #+#              #
#    Updated: 2023/08/28 13:40:14 by dyanez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
