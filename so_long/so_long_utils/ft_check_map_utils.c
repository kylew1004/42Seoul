/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klew <klew@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:40:11 by klew              #+#    #+#             */
/*   Updated: 2022/10/14 14:13:21 by klew             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_err_message(t_map_data *map)
{
	if (map->c == 0)
		return (
			"element 'C' is missing");
	if (map->p == 0)
		return (
			"element 'P' is missing");
	if (map->e == 0)
		return (
			"element 'E' is missing");
	if (map->p == 0)
		return (
			"element 'P' is missing");
	if (map->p > 1)
		return (
			"there is more then one element 'P'");
	return ("element missing in the map");
}

char	*unknown_element(t_data ***data, char c)
{
	int	x;

	x = 0;
	while ((**data)->map[x])
	{
		free((**data)->map[x]);
		x++;
	}
	free((**data)->map);
	printf("Wrong element! => %c", c);
	exit(1);
}

void	check_elements(t_data **data)
{
	t_map_data	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*data)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*data)->map[map.y][map.x] != '\0')
		{
			if ((*data)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*data)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*data)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*data)->map[map.y][map.x] != '1' &&
				(*data)->map[map.y][map.x] != '0')
				unknown_element(&data, (*data)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&data, ft_err_message(&map));
}
