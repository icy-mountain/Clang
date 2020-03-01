# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuehara <yuehara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 09:57:11 by yuehara           #+#    #+#              #
#    Updated: 2020/02/23 18:10:13 by yuehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# vpath %.c src

SRCS = main.c lib.c filelib.c dictlib.c dict2lib.c dict_check.c strlib.c write_sp.c
INCS = includes
NAME = a.out
CC = gcc
FLAGS = -Wall -Wextra -Werror
RMF = rm -f

${NAME}:
	${CC} ${FLAGS} ${SRCS} -I ${INCS}

all: ${NAME}

clean:
	${RMF} ${NAME}

fclean:
	${RMF} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re
