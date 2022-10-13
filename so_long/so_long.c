/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:19:51 by klew              #+#    #+#             */
/*   Updated: 2022/10/13 12:08:22 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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