NAME		= Brain

SRCS		= srcs/Brain.cpp \
			  srcs/main.cpp	\
			  srcs/Cat.cpp \
			  srcs/Dog.cpp \
			  srcs/Animal.cpp \
			  srcs/WrongAnimal.cpp \
			  srcs/WrongCat.cpp

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -f

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

COMPILER	= c++

${NAME}:	${OBJS}
		${COMPILER} ${CPPFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
