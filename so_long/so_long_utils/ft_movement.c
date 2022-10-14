/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:49:27 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 14:13:31 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	collected(t_data ***data)
{
	int		img_w;
	int		img_h;

	(**data)->collect--;
	(**data)->map[((**data)->y_p / 50)][((**data)->x_p / 50)] = '0';
	(**data)->img = mlx_xpm_file_to_image(
			(**data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**data)->mlx, (**data)->win, (**data)->img, \
		(**data)->x_p, (**data)->y_p);
}

void	to_left(t_data **data)
{
	int		img_w;
	int		img_h;

	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50) - 1] == 'E')
	{
		if ((*data)->collect <= 0)
			exit_door(&data);
	}
	else if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50) - 1] != '1')
	{
		(*data)->x_p -= 50;
		put_text(&data);
	}
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50)] == 'C')
		collected(&data);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/left.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
}

void	to_right(t_data **data)
{
	int		img_w;
	int		img_h;

	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50) + 1] == 'E')
	{
		if ((*data)->collect <= 0)
			exit_door(&data);
	}
	else if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50) + 1] != '1')
	{
		(*data)->x_p += 50;
		put_text(&data);
	}
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50)] == 'C')
		collected(&data);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/right.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
}

void	to_up(t_data **data)
{
	int		img_w;
	int		img_h;

	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
	if ((*data)->map[((*data)->y_p / 50) - 1][((*data)->x_p / 50)] == 'E')
	{
		if ((*data)->collect <= 0)
			exit_door(&data);
	}
	else if ((*data)->map[((*data)->y_p / 50) - 1][((*data)->x_p / 50)] != '1')
	{
		(*data)->y_p -= 50;
		put_text(&data);
	}
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50)] == 'C')
		collected(&data);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/back.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
}

void	to_down(t_data **data)
{
	int		img_w;
	int		img_h;

	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
	if ((*data)->map[((*data)->y_p / 50) + 1][((*data)->x_p / 50)] == 'E')
	{
		if ((*data)->collect <= 0)
			exit_door(&data);
	}
	else if ((*data)->map[((*data)->y_p / 50) + 1][((*data)->x_p / 50)] != '1')
	{
		(*data)->y_p += 50;
		put_text(&data);
	}
	if ((*data)->map[((*data)->y_p / 50)][((*data)->x_p / 50)] == 'C')
		collected(&data);
	(*data)->img = mlx_xpm_file_to_image(
			(*data)->mlx, "./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*data)->mlx, (*data)->win, (*data)->img, (*data)->x_p, (*data)->y_p);
}
