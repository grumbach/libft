# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 17:19:11 by agrumbac          #+#    #+#              #
#    Updated: 2018/06/26 17:49:15 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## BIN #############################################

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g -Wno-incompatible-pointer-types -Wno-compare-distinct-pointer-types

SRC = btree_test.c

LIB = -L.. -lft

INCLUDES = -I../includes/

OBJ = $(SRC:.c=.o)

############################## COLORS ##########################################

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

############################## RULES ###########################################

.SILENT:

all: ${NAME}

${NAME}: ${OBJ}
	@make -C .. all
	@echo ${B}Compiling [${NAME}]...${X}
	@${CC} ${CFLAGS} ${INCLUDES} ${LIB} -o $@ ${OBJ}
	@echo ${G}Success"   "[${NAME}]${X}

%.o: %.c
	@echo ${Y}Compiling [$@]...${X}
	@${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<
	@printf ${UP}${CUT}

############################## GENERAL #########################################

clean:
	@echo ${R}Cleaning"  "[libft objs]...${X}
	@make -C .. clean
	@echo ${R}Cleaning"  "[objs]...${X}
	@/bin/rm -f ${OBJ}

fclean: clean
	@make -C .. fclean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

re: fclean all

.PHONY: all clean fclean re art
