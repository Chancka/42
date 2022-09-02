# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:15:05 by cboudrin          #+#    #+#              #
#    Updated: 2022/06/20 14:20:10 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philo

SRCS	=	check.c philo.c init.c routine_utils.c utils.c init2.c free_philo.c

HEADERS	=	philo.h

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -I./include

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -g ${OBJS} -pthread -o ${NAME} 


%.o:		%.c	${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
