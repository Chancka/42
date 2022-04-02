# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 09:36:39 by cboudrin          #+#    #+#              #
#    Updated: 2022/03/02 13:17:52 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/decoupe.c src/input.c src/mouvement.c src/push_swap.c \
				src/solve_all.c src/solve.c src/printf/ft_printf.c \
				src/printf/ft_print_nbr.c src/printf/ft_print_hexa.c \
				src/printf/ft_print_ptr.c src/printf/ft_print_u.c \
				src/printf/ft_putchar.c src/printf/ft_print_str.c \
				src/ft_isdigit.c src/ft_atoi.c src/ft_putstr_error.c

OBJS		= ${SRCS:.c=.o}

INCL		= src/push_swap.h

NAME		= push_swap

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}


${NAME}:	${OBJS} ${INCL}
				gcc ${CFLAGS} ${OBJS} ${INCL} -o ${NAME} -fsanitize=address

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
