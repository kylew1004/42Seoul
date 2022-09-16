# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 13:07:28 by klew              #+#    #+#              #
#    Updated: 2022/09/16 14:04:37 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	server
NAME2			=	client
NAMEB			=	server_bonus
NAMEB2			=	client_bonus
CFLAG			=	-Weror -Wall -Wextra

CC				=	cc
RM				=	rm -rf

SRCS			=	server.c
SRCS2			=	client.c
SRCSB			=	server_bonus.c
SRCSB2			=	client_bonus.c

OBJS			= $(SRCS:%.c=%.o)
OBJS2			= $(SRCS2:%.c=%.o)
OBJSB			= $(SRCSB:%.c=%.o)
OBJSB2			= $(SRCSB2:%.c=%.o)

all:			$(NAME) $(NAME2) bonus

$(NAME):		$(OBJS)
				$(CC) $(CFLAG) $(OBJS) -o $(NAME)
				
$(NAME2):		$(OBJS2)
				$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)

$(NAMEB):		$(OBJSB)
				$(CC) $(CFLAG) $(OBJSB) -o $(NAMEB)
				
$(NAMEB2):		$(OBJSB2)
				$(CC) $(CFLAG) $(OBJSB2) -o $(NAMEB2)

bonus:			$(NAMEB) $(NAMEB2)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS2)
				$(RM) $(OBJSB)
				$(RM) $(OBJSB2)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME2)
				$(RM) $(NAMEB)
				$(RM) $(NAMEB2)

re:				fclean all

.PHONY:			all clean fclean re
