# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 09:24:28 by klew              #+#    #+#              #
#    Updated: 2023/05/24 12:31:30 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert

CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f

SRC			=	main.cpp \
				Converter.cpp
				
OBJ			=	$(SRC:.cpp=.o)

all : $(NAME) 

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)

clean :
	@$(RM) $(OBJ)

fclean :
	@$(MAKE) clean
	@$(RM) $(NAME)

re : 
	@$(MAKE) fclean
	@$(MAKE) all

PHONY : all clean fclean re