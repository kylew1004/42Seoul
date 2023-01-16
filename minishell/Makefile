# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 09:46:05 by klew              #+#    #+#              #
#    Updated: 2023/01/16 09:48:31 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
LIBFT = ./libft
LIB = $(LIBFT)/libft.a

INCLUDES =	-I/Users/klew/homebrew/opt/readline/include\
			-I./includes\
			-I$(LIBFT)

LIBDIRS =	-L/Users/klew/homebrew/opt/readline/lib\
			-L$(LIBFT)

LIBS =	-lreadline\
		-lft

SDIR = ./src
SRCS =	minishell.c\
		minishell_utils.c\
		parse.c\
		check_tokens.c\
		ft_split_shell.c\
		signals.c\


ODIR = ./obj
OBJS = $(patsubst %,$(ODIR)/%,$(SRCS:.c=.o))

$(ODIR)/%.o : $(SDIR)/*/%.c
	@mkdir -p obj
	@echo "Creating object : $@"
	@$(COMPILE) $(INCLUDES) -c -o $@ $<

all: libft | $(NAME)

$(NAME): $(LIB) $(OBJS)
	@echo "Creating executable $(NAME)"
	@$(COMPILE) $(OBJS) $(LIBDIRS) $(LIBS) -o $(NAME)

run: $(NAME)
	@./$<
	@echo "Worked just fine"

clean:
	@echo "Removing object files $(NAME)"
	@rm -rf $(OBJS) $(ODIR)
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@echo "Removing executable file $(NAME)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT)

libft:
	@$(MAKE) -C $(LIBFT)

re: fclean | all

.PHONY: all clean fclean libft run re
