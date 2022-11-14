SRCS		=	srcs/Contact.cpp srcs/main.cpp srcs/PhoneBook.cpp

CC			=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3

RM			=	rm -f

NAME		=	PhoneBook

OBJ			=	$(SRCS:.cpp=.o)

all			:	$(NAME) 

%.o : %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $< 

$(NAME)		:	$(OBJ)
				$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean
				$(MAKE)

.PHONY		:	clean fclean re all
