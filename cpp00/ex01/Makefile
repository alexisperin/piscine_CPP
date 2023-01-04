# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 11:35:14 by aperin            #+#    #+#              #
#    Updated: 2023/01/04 13:29:11 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

SRCS	= PhoneBook.cpp \
			Contact.cpp \
			main.cpp

OBJDIR		= objs

CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

OBJS		= $(addprefix ${OBJDIR}/, $(addsuffix .o, $(basename ${SRCS})))

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