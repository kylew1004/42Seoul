/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:17:33 by klew              #+#    #+#             */
/*   Updated: 2022/10/13 12:20:21 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_img(t_data **data)
{
	int			img_w;
	int			img_h;

	(*data)->e_data.imgs[0] = "./img/1.xpm";
	(*data)->e_data.imgs[1] = "./img/2.xpm";
	(*data)->e_data.imgs[2] = "./img/3.xpm";
	(*data)->e_data.imgs[3] = "./img/2.xpm";
	(*data)->e_data.imgs[4] = "./img/1.xpm";
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img,
		(*data)->e_data.x_e * 50, (*data)->e_data.y_e * 50);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, (*data)->e_data.imgs[(*data)->e_data.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img,
		(*data)->e_data.x_e * 50, (*data)->e_data.y_e * 50);
}

void	move_enemy(t_data **data)
{
	int			img_w;
	int			img_h;

	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img,
		(*data)->e_data.x_e * 50, (*data)->e_data.y_e * 50);
	if ((*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e + 1] != '1' &&
		(*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e + 1] != 'C' &&
		(*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e + 1] != 'E' &&
		(*data)->e_data.path_to_move == 0)
		(*data)->e_data.x_e++;
	else
		(*data)->e_data.path_to_move = 1;
	if ((*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e - 1] != '1' &&
		(*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e - 1] != 'C' &&
		(*data)->map[(*data)->e_data.y_e][(*data)->e_data.x_e - 1] != 'E' &&
		(*data)->e_data.path_to_move == 1)
		(*data)->e_data.x_e--;
	else
		(*data)->e_data.path_to_move = 0;
}

static void	ft_lose(t_data **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	printf("%s", err);
	exit(0);
}

int	animation(t_data *data)
{
	if (get_position_for_enemy(&data) != 0)
	{
		if (data->e_data.sleep-- <= 0)
		{
			data->e_data.x++;
			data->e_data.sleep = 5;
		}
		if (data->e_data.x == 3)
			data->e_data.x = 0;
		if (data->e_data.sleep_for_move-- <= 0)
		{
			move_enemy(&data);
			data->e_data.sleep_for_move = 30;
		}
		if ((data->e_data.y_e == data->y_p / 50)
			&& (data->e_data.x_e == data->x_p / 50))
		{
			ft_lose(&data, "You Lose :(");
		}
		render_img(&data);
	}
	if (data->collect <= 0)
		open_exit(&data);
	return (0);
}
