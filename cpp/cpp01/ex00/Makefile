NAME        = zombie

SRCS        = srcs/main.cpp srcs/zombie.cpp srcs/newZombie.cpp srcs/randomChump.cpp

OBJS        = ${SRCS:.cpp=.o}

RM          = rm -f

CFLAGS      = -Wall -Wextra -Werror -std=c++98

COMPILER    = c++

${NAME}: ${OBJS}
		${COMPILER} ${FLAGS} ${OBJS} -o ${NAME}

all :   ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:        fclean all

.PHONY: all clean fclean re

