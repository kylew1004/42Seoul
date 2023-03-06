# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:02:29 by klew              #+#    #+#              #
#    Updated: 2023/03/06 11:07:51 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \

OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -std=c++98 -Wall -Werror -Wextra

NAME			= zombiehorde

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(OBJS) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test