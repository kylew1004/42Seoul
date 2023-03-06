# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:03:07 by klew              #+#    #+#              #
#    Updated: 2023/03/06 11:08:05 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
					Harl.cpp \

OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -std=c++98 -Wall -Werror -Wextra

NAME			= Harl

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(OBJS) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test