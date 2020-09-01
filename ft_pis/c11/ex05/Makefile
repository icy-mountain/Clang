# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykori <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 17:05:44 by ykori             #+#    #+#              #
#    Updated: 2020/02/27 16:49:05 by ykori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
GCCW = gcc -Wall -Wextra -Werror -o $(NAME) -I ../includes 
CSRCS = main.c ft_atoi.c doop.c ope.c ft_putnbr.c write_err.c 

all: $(NAME)

$(NAME):
	cd ./srcs && $(GCCW) $(CSRCS) && mv $(NAME) ./.. && cd ..

clean:
	rm -f srcs/*.o	

fclean: clean
	rm -f $(NAME)

re: fclean all
