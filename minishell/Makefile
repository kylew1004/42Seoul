# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 09:46:05 by klew              #+#    #+#              #
#    Updated: 2023/01/21 03:44:23 by junhelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_D = -g -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
LIBFT = ./libft
LIB = $(LIBFT)/libft.a

INCLUDES =	-I$${HOME}/.brew/opt/readline/include\
			-I./includes\
			-I$(LIBFT)

LIBDIRS =	-L$${HOME}/.brew/opt/readline/lib\
			-L$(LIBFT)\

LIBS =	-lreadline\
		-lft

SDIR = ./src
SRCS =	minishell.c\
		minishell_utils.c\
		pipex.c\
		pipex_utils.c\
		parse.c\
		check_tokens.c\
		ft_split_shell.c\
		ft_split_cmd.c\
		ft_strip_quotes.c\
		signals.c\
		expansions.c expansions_utils.c ft_getenv.c\
		builtin_echo.c builtin_cd.c builtin_pwd.c builtin_exit.c \
		builtin_env.c builtin_export.c builtin_unset.c search_builtin.c \
		variable.c environment.c sort_var.c \
		redirection.c heredoc.c control_redirect.c get_splitted_redirect.c heredoc_utils.c\
		remove_redirections.c control_execute.c execute_utils.c

ODIR = ./obj
OBJS = $(patsubst %,$(ODIR)/%,$(SRCS:.c=.o))

$(ODIR)/%.o : $(SDIR)/*/%.c
	@mkdir -p obj
	@echo "Creating object : $@"
	@$(COMPILE) $(INCLUDES) -c -o $@ $<

all: $(NAME)

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

$(addprefix libft/,libft.a):
	@$(MAKE) -C $(LIBFT) bonus

re: fclean | all

.PHONY: all clean fclean libft run re
