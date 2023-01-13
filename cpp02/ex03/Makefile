# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 14:23:31 by aperin            #+#    #+#              #
#    Updated: 2023/01/12 15:42:36 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex03

SRCS	= main.cpp \
			Fixed.cpp \
			Point.cpp \
			bsp.cpp

OBJDIR	= objs

CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJS	= $(addprefix ${OBJDIR}/, $(addsuffix .o, $(basename ${SRCS})))

${OBJDIR}/%.o: %.cpp
			@mkdir -p ${OBJDIR}
			${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -rf ${OBJDIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME