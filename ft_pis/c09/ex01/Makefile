# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykori <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 10:06:18 by ykori             #+#    #+#              #
#    Updated: 2020/02/27 16:15:08 by ykori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GCCW = gcc -c -Wall -Wextra -Werror -I ../includes
CSRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c 
OSRCS = ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o

all: libft.a

libft.a:
	cd ./srcs && $(GCCW) $(CSRCS) && cd .. && ar rc libft.a $(OSRCS)

clean:
	rm -f $(OSRCS)

fclean: clean
	rm -f libft.a

re: fclean all
