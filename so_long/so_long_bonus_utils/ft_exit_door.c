/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:44:28 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 13:35:08 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_door(t_data ***data)
{
	int	x;

	x = 0;
	while ((**data)->map[x])
	{
		free((**data)->map[x]);
		x++;
	}
	free((**data)->map);
	mlx_destroy_window((**data)->mlx, (**data)->win);
	exit(1);
}
