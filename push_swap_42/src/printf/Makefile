# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 09:36:39 by cboudrin          #+#    #+#              #
#    Updated: 2022/01/06 15:57:21 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c\
			ft_print_nbr.c\
			ft_print_hexa.c\
			ft_print_ptr.c\
			ft_print_u.c\
			ft_putchar.c\
			ft_print_str.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			 @ar -rcs $(NAME) $^

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
