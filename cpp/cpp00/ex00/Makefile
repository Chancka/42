NAME        = megaphone

SRCS        = srcs/megaphone.cpp

OBJS        = ${SRCS:.cpp=.o}

RM			= rm -f

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

COMPILER    = c++

%.o : %.cpp %.h
	$(CC) $(CPPFLAGS) -o $@ -c $< 

${NAME}: ${OBJS}
		${COMPILER} ${CPPFLAGS} ${OBJS} -o ${NAME}

all :   ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:        fclean all

.PHONY: all clean fclean re

