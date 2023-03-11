# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 19:14:37 by klew              #+#    #+#              #
#    Updated: 2023/03/09 19:14:38 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp

OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I -std=c++98

NAME			= ScavTrap

all:			$(NAME)

$(NAME):		$(OBJS) ClapTrap.hpp ScavTrap.hpp
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(OBJS) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test