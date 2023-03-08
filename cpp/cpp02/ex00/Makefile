# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 20:09:02 by klew              #+#    #+#              #
#    Updated: 2023/03/08 11:32:44 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
					Fixed.cpp

OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I -std=c++98

NAME			= Fixed

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(OBJS) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test