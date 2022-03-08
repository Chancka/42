# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 09:36:39 by cboudrin          #+#    #+#              #
#    Updated: 2022/03/08 13:59:13 by cboudrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERVER = minitalk_server.c minitalk_utils.c
SRC_CLIENT = minitalk_client.c minitalk_utils.c

NAME_SERVER = server
NAME_CLIENT = client

OBJ_SRV = minitalk_server.o minitalk_utils.o
OBJ_CLIENT = minitalk_client.o minitalk_utils.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SRV)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SRV)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)


clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SRV)

fclean:	clean
	rm -f $(OBJ_CLIENT) $(OBJ_SRV) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: server client all re fclean clean