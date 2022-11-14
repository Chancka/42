SRCS		=	srcs/main.cpp srcs/Zombie.cpp srcs/newZombie.cpp srcs/randomChump.cpp

CC			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

NAME		=	zombie

OBJS		=	$(SRCS:.cpp=.o)

all			:   $(NAME)

%.o : %.cpp %.hpp
	$(CC) $(CPPFLAGS) -o $@ -c $< 

$(NAME)		:	$(OBJS)
				$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)

re			:	fclean all

.PHONY: all clean fclean re

