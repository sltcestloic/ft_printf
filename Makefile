# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/01/12 10:44:11 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c \
			flags.c \
			print.c \
			utils/ft_putchar.c \
			utils/is_valid.c \
			types/print_chars.c \
			types/print_hexa.c \
			types/print_int.c \
			types/print_percent.c \
			types/print_pointer.c \
			types/print_uint.c
OBJ		= ${SRC:.c=.o}
SRCS 	= $(addprefix srcs/, ${SRC})
OBJS 	= $(addprefix .objs/, ${OBJ})
INCS	= includes
NAME	= libftprintf.a
LIBC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.objs/%.o: srcs/%.c ${INCS}/ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

${NAME}: ${OBJS}
	@${MAKE} bonus -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re .c.o
