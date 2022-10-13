/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:34:05 by klew              #+#    #+#             */
/*   Updated: 2022/10/13 15:46:32 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"

int		animation(t_vars *vars);

#endif