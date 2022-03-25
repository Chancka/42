# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 13:11:03 by cboudrin          #+#    #+#              #
#    Updated: 2022/03/25 16:35:53 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INC			=	include

SRCS		=	so_long.c

MLX			=	/usr/local/lib/

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

RM			=	rm -f

CFLAGS 		=	-Wall -Werror -Wextra -g
FLAGS_MLX	=	-I -L -Lincludes -L./mlx -lmlx -lXext -lX11 -lz -lm -fsanitize=address

all			:	$(NAME)

%.o			:  %.c
				$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME)		:	$(OBJS)
				make all -C ./libft
				$(CC) $(OBJS) $(FLAGS_MLX) ./libft/libft.a -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re 			:	fclean all
