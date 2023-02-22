# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 19:23:57 by klew              #+#    #+#              #
#    Updated: 2023/02/22 20:07:52 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = Account.cpp test.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re
