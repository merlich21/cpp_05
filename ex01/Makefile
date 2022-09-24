# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 18:46:22 by merlich           #+#    #+#              #
#    Updated: 2022/08/27 20:53:26 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bureaucrat

SRCS		=	main.cpp Bureaucrat.cpp Form.cpp

OBJS		=	${SRCS:.cpp=.o}

D_FILES		=	${SRCS:.cpp=.d}

CPP			=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD

RM			=	rm -f

%.o:		%.cpp Makefile
			${CPP} ${CPPFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} Makefile
			${CPP} ${OBJS} -o ${NAME}

-include ${D_FILES}

clean:
			${RM} ${OBJS} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
