/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:38:59 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 14:08:24 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check(t_data ***data, int x, int y)
{
	if ((**data)->map[y][x] == '0' && (**data)->map[y][x + 1] == '0'
		&& (**data)->map[y][x + 2] == '0')
	{
		(**data)->e_data.sign = 0;
		(**data)->e_data.x_e = x;
		(**data)->e_data.y_e = y;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_data **data)
{
	int			y;
	int			x;
	int			height;

	y = 0;
	height = get_height((*data)->map);
	if ((*data)->e_data.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*data)->map[y][x] != '\0')
			{
				if (check(&data, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	open_exit(t_data **data)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*data)->map);
	while (y != height)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'E')
			{
				(*data)->img = mlx_xpm_file_to_image(
						(*data)->mlx, "./img/open_door.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*data)->mlx, (*data)->win, (*data)->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
