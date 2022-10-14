/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:19:51 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 13:42:54 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_data *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
	return (0);
}

void	render_map(t_data *datas)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = datas->win_w;
	while (datas->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (datas->win_w > 0)
		{
			put_image_to_map(datas->map[y_map][x_map], x1, y1, &datas);
			x_map++;
			x1 += 50;
			datas->win_w--;
		}
		datas->win_w = backup_w;
		y_map++;
		y1 += 50;
		datas->win_h--;
	}
}

static void	init_data(t_data *datas)
{
	datas->collect = 0;
	datas->movement = 0;
	datas->win_w = ft_strlen(datas->map[0]);
	datas->win_h = get_height(datas->map);
	datas->e_data.sign = 1;
	datas->e_data.x = 0;
	datas->e_data.sleep = 5;
	datas->e_data.sleep_for_move = 60;
	datas->e_data.path_to_move = 0;
}

int	key_hook(int keycode, t_data *data)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(&data);
	else if (keycode == 0 || keycode == 123)
		to_left(&data);
	else if (keycode == 13 || keycode == 126)
		to_up(&data);
	else if (keycode == 1 || keycode == 125)
		to_down(&data);
	else if (keycode == 53)
	{
		x = 0;
		while (data->map[x])
		{
			free(data->map[x]);
			x++;
		}
		free(data->map);
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1)
	{
		perror("./so_long [MAP_FILE.ber]");
		exit(1);
	}
	check_file(argv[1]);
	data.map = get_map(argv[1]);
	if (data.map != NULL)
	{
		check_map_valid(&data);
		init_data(&data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx,
				data.win_w * 50, data.win_h * 50, "So-Long");
		render_map(&data);
		mlx_hook(data.win, 2, (1L << 0), key_hook, &data);
		mlx_hook(data.win, 17, (1L << 0), ft_exit, &data);
		mlx_string_put(data.mlx, data.win, 5, 10, 0xffffff, "Step: 0");
		mlx_loop_hook(data.mlx, animation, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
