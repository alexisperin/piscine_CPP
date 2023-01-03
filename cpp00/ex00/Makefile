# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:38:11 by aperin            #+#    #+#              #
#    Updated: 2023/01/03 09:58:27 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

%.o : %.cpp
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re NAME