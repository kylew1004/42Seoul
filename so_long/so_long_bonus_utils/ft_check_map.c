/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:43:29 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 14:06:20 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_error(t_data ***data, char *err)
{
	int	x;

	x = 0;
	while ((**data)->map[x])
	{
		free((**data)->map[x]);
		x++;
	}
	free((**data)->map);
	printf("%s", err);
	exit(1);
}

static void	check_is_rectangular(t_data **data)
{
	int	y_map;
	int	x_map;
	int	height;
	int	backup;

	y_map = 0;
	backup = 0;
	height = get_height((*data)->map);
	while (y_map != height)
	{
		x_map = 0;
		while ((*data)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error(&data,
					"ERROR: map is not rectangular!");
		}
		else
			backup = x_map;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_surrounded_by_walls(t_data **data)
{
	int		i;
	char	*err;

	err = "map is not surrounded by walls!";
	if (check_line((*data)->map[0]))
		ft_error(&data, err);
	i = get_height((*data)->map) - 1;
	while (i)
	{
		if ((*data)->map[i][0] != '1' ||
			(*data)->map[i][ft_strlen((*data)->map[i]) - 1] != '1')
		{
			ft_error(&data, err);
		}
		i--;
	}
	if (check_line((*data)->map[get_height((*data)->map) - 1]))
		ft_error(&data, err);
}

void	check_map_valid(t_data *data)
{
	check_is_rectangular(&data);
	check_surrounded_by_walls(&data);
	check_elements(&data);
}
