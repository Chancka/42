NAME		= Intern

SRCS		= srcs/Bureaucrat.cpp \
			  srcs/main.cpp \
			  srcs/Form.cpp \
			  srcs/ShrubberyCreationForm.cpp \
			  srcs/RobotomyRequestForm.cpp \
			  srcs/PresidentialPardonForm.cpp \
			  srcs/Intern.cpp

OBJS		= ${SRCS:%.cpp=%.o}

RM			= rm -f

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

COMPILER	= c++

%.o: %.cpp
	${COMPILER} ${CPPFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
		${COMPILER} ${CPPFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
