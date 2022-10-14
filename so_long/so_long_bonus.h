/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:34:05 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 13:43:45 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_enemy_data {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy_data;

typedef struct s_data {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	int				collect;
	char			**map;
	t_enemy_data	e_data;
}	t_data;

typedef struct s_map_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_data;

int				get_position_for_enemy(t_data **data);
void			open_exit(t_data **data);
void			render_img(t_data **data);
void			move_enemy(t_data **data);
int				animation(t_data *vars);
void			check_file(char *file_line);
char			*unknown_element(t_data ***v, char c);
void			check_elements(t_data **vars);
void			ft_error(t_data ***data, char *err);
void			check_map_valid(t_data *data);
void			exit_door(t_data ***data);
char			*ft_strdup(const char *s1);
int				get_height(char **map);
char			**get_map(char *fmap);
void			ft_build_str(size_t len, char *str, int n, int neg);
char			*ft_itoa(int n);
void			to_left(t_data **data);
void			to_right(t_data **data);
void			to_up(t_data **data);
void			to_down(t_data **data);
void			put_image(t_data ***v, int x, int y, char *img);
void			put_image_to_map(char p, int x1, int y1, t_data **v);
void			put_text(t_data ***data);
char			*ft_strndup(const char *s, size_t n);
char			**ft_freeall(char **list);
size_t			ft_wordcount(char const *s, char c);
char			**ft_split(char const *s, char c);

#endif