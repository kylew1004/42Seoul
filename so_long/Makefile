# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klew <klew@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 12:47:39 by klew              #+#    #+#              #
#    Updated: 2022/10/14 13:52:56 by klew             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	so_long
NAME_BONUS 	= 	so_long_bonus
CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror

SRCS		=	./so_long_utils/ft_animation_utils.c			\
				./so_long_utils/ft_animation.c					\
				./so_long_utils/ft_check_file.c					\
				./so_long_utils/ft_check_map_utils.c			\
				./so_long_utils/ft_check_map.c					\
				./so_long_utils/ft_exit_door.c					\
				./so_long_utils/ft_get_map.c					\
				./so_long_utils/ft_itoa.c						\
				./so_long_utils/ft_movement.c					\
				./so_long_utils/ft_put_text.c					\
				./so_long_utils/ft_put_image.c					\
				./so_long_utils/ft_split.c						\
				./get_next_line/get_next_line_utils.c			\
				./get_next_line/get_next_line.c					\
				so_long.c
OBJS		= 	$(SRCS:.c=.o)
SRCS_BONUS 	=	./so_long_bonus_utils/ft_animation_utils.c		\
				./so_long_bonus_utils/ft_animation.c			\
				./so_long_bonus_utils/ft_check_file.c			\
				./so_long_bonus_utils/ft_check_map_utils.c		\
				./so_long_bonus_utils/ft_check_map.c			\
				./so_long_bonus_utils/ft_exit_door.c			\
				./so_long_bonus_utils/ft_get_map.c				\
				./so_long_bonus_utils/ft_itoa.c					\
				./so_long_bonus_utils/ft_movement.c				\
				./so_long_bonus_utils/ft_put_text.c				\
				./so_long_bonus_utils/ft_put_image.c			\
				./so_long_bonus_utils/ft_split.c				\
				./get_next_line/get_next_line_utils.c			\
				./get_next_line/get_next_line.c					\
				so_long_bonus.c
OBJS_BONUS	= 	$(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re