# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 13:11:03 by cboudrin          #+#    #+#              #
#    Updated: 2022/04/02 15:42:46 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

INC			=	include

SRCS		=	src/so_long.c src/check_map.c src/check_utils.c src/free.c\
					src/ft_img.c src/ft_img_utils.c src/ft_key.c src/parse_map.c\
					get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

BONUS_S 	=	src_bonus/so_long.c src_bonus/check_map.c src_bonus/check_utils.c\
					src_bonus/free.c src_bonus/ft_img.c src_bonus/ft_img_utils.c\
					src_bonus/ft_key.c src_bonus/parse_map.c src_bonus/ft_img_bonus.c\
					get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
					src_bonus/so_long2.c\

BONUS_O		=	${BONUS_S:.c=.o}

MLX			=	/usr/local/lib/

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

RM			=	rm -f

CFLAGS 		=	-Wall -Werror -Wextra -g
FLAGS_MLX	=	-I -L -Lincludes -L./mlx -lmlx -lXext -lX11 -lz -lm

all			:	$(NAME)

%.o			:  %.c
				$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME)		:	$(OBJS)
				make all -C ./libft
				make all -C ./printf
				make all -C ./mlx
				$(CC) $(OBJS) $(FLAGS_MLX) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

bonus		:	${NAME} $(BONUS_O)
				$(CC) $(BONUS_O) $(FLAGS_MLX) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(BONUS_O)

re 			:	fclean all
