# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 13:11:03 by cboudrin          #+#    #+#              #
#    Updated: 2022/03/31 13:01:55 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INC			=	include

SRCS		=	put_image.c check_map.c check_utils.c parse_map.c free.c ../get_next_line/get_next_line.c\
					../get_next_line/get_next_line_utils.c

MLX			=	/usr/local/lib/

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

RM			=	rm -f

CFLAGS 		=	-Wall -Werror -Wextra -g
FLAGS_MLX	=	-g -I -L -Lincludes -L../mlx -lmlx -lXext -lX11 -lz -lm 

all			:	$(NAME)

%.o			:  %.c
				$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME)		:	$(OBJS)
				make all -C ../libft
				make all -C ../printf
				$(CC) $(OBJS) $(FLAGS_MLX) ../libft/libft.a ../printf/libftprintf.a -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re 			:	fclean all
