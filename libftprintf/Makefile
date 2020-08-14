# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykori <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 10:06:18 by ykori             #+#    #+#              #
#    Updated: 2020/06/24 20:54:00 by ykori            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRC:.c=.o)
# OBJS = $(subst src,obj,$(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include

# hoge:
# 	@echo $(OBJS)

all: $(NAME)

comp: 
	gcc $(SRC)  -I ./include -o a.out

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OSRCSB)

bonus:$(OBJS)
	ar rc $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all comp clean bonus fclean re