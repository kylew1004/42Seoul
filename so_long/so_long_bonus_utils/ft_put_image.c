/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:48:58 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 14:05:34 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_image(t_data ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_data **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./img/wall.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./img/floor.xpm");
		put_image(&v, x1, y1, "./img/collect.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./img/exit_door.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		put_image(&v, x1, y1, "./img/floor.xpm");
		put_image(&v, x1, y1, "./img/front.xpm");
	}
	else
		put_image(&v, x1, y1, "./img/floor.xpm");
}
