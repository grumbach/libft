# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 17:08:23 by agrumbac          #+#    #+#              #
#    Updated: 2016/12/27 00:19:35 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_abs.c \
ft_arraynew.c \
ft_arrayadd.c \
ft_arraydel.c \
ft_atoi.c \
ft_bzero.c \
ft_fac.c \
ft_gcd.c \
ft_get_next_line.c \
ft_intlen.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstaddend.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_pow.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_sqrt.c \
ft_strcat.c \
ft_strchr.c \
ft_strchrn.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c

OBJ = $(SRC:.c=.o)

SRCDIR = ./srcs/

SRCH = ./includes/

OBJH = ./includes/libft.h.gch

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all:${NAME}

${NAME}:
	${CC} -I ${SRCH} -c $(addprefix ${SRCDIR}, ${SRC}) ${CFLAGS}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

clean:
	rm -f ${OBJ}
	rm -f ${OBJH}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean
